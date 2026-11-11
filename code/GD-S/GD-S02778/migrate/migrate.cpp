#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll fa[2000050],x[2000006],ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        memset(fa,0,sizeof(fa));
        int n,d,f = 1,f1 = 0;
        cin>>n>>d;
        for(int i = 1;i<=n;i++) cin>>x[i];
        for(int i = 3;i<=n;i++){
            if((x[i]-x[i-1])!=(x[i-1]-x[i-2])) {f = 0;break;}
        }
        if(f){
            if(d>=x[2]-x[1]) {cout<<n-3<<"\n";continue;}
            else {cout<<"0";continue;}
        }
        if(!f){
            for(int i = 3;i<=n;i++){
                for(int j = 1;j<=i-2;j++){
                    if(x[j+1]-x[j]+x[j+2]-x[j+1]==x[j+2]-x[j]) ans++;//vis[i][j]=1;
                }
            }
            cout<<ans;
        }
    }
    return 0;
}
