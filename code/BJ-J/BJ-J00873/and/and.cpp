#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1000;
int n,m,a[N];
int f[2010][2010]={};
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(n<=2000&&m<=2000){
        for(int i=1;i<=n;i++){
            cin >> a[i];
            f[i][1]=a[i];
        }
        if(n==m){
            int cnt=a[1];
            for(int i=2;i<=n;i++){
                cnt=(a[i]&cnt);
            }
            cout << cnt << " ";
            return 0;
        }
        int max_=-1e9;
        for(int j=2;j<=m;j++){
            for(int i=1;i<=n;i++){
                for(int k=1;k<i;k++){
                    f[i][j]=max((f[k][j-1]&a[i]),f[i][j]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            max_=max(max_,f[i][m]);
        }
        cout << max_;
    }else{
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1,cmp);
        int cnt=a[1];
        for(int i=2;i<=n;i++){
            cnt=(a[i]&cnt);
        }
        cout << cnt << " ";
    }

    return 0;
}

