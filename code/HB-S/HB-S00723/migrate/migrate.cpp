#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005;
vector<vector<int> >a(maxn,vector<int>(maxn,0));
vector<int> b(maxn,0);
int n,d;
vector<int> x(maxn,0);
void f(int d,int k,int v){
    int j=k;
    int u=x[1];
    for(int i=d;i>=1;i--){
        while(j<=n){
            if(i>=abs(x[j+1]-u)){
                j++;
                f(d-v,j,v+1);
                b[i]++;
            }
            u=x[j];
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    if(c==0)
    while(t--){
        x.clear();
        a.clear();
        b.clear();

        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        f(d,1,1);
        int ans=0;
        for(int i=1;i<d;i++){
            for(int j=i+1;j<=d;j++){
                if(b[i]=b[j]){
                    ans++;
                }
            }
        }
        cout<<ans;
    }

    return 0;
}
