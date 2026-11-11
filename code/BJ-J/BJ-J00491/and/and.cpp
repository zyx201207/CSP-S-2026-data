#include<bits/stdc++.h>
using namespace std;
using Ull = unsigned long long;
constexpr Ull N = 2e5+10;
int n,m,a[N],f[2][N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(m==n){
        for(int i=2;i<=n;++i){
            a[1]&=a[i];
        }
        cout<<a[1]<<flush;
        return 0;
    }
    //f[flag][i] = max(f[flag][i-1],f[!flag][h]&a[i] max)
    bool flag = 0;
    for(int j=1;j<=m;++j){
        flag = !flag;
        for(int i=1;i<j;++i)
            f[flag][i] = -1;
        for(int i=j;i<=n;++i){
            if(j==1){
                f[flag][i] = a[i];
                continue;
            }
            int mx = -1;
            for(int h=j-1;h<=n;++h){
                if(h==i) continue;
                mx = max(mx,a[i]&f[!flag][h]);
                //cout<<a[i]<<"&f["<<!flag<<"]["<<h<<"]("<<f[!flag][h]<<") = "<<(a[i]&f[!flag][h])<<endl;
            }
            f[flag][i] = mx;
        }
        /*
        cout<<j<<":\t"<<flag<<"\t";
        for(int i=1;i<=n;++i){
            cout<<f[flag][i]<<"\t";
        }
        cout<<'\n';
        */
    }
    int mx = 0;
    for(int i=1;i<=n;++i){
        mx = max(mx,f[flag][i]);
    }
    cout<<mx<<flush;
    return 0;
}
