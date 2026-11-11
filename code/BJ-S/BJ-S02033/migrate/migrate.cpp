#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int N=1e3+10;
        int n,d;
        int a[N];
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        queue<int>q[N][N];
        int m[N][N]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                m[i][j]=1e18;
            }
        }
        if(n==0||n==1){
            cout<<"0\n";
            continue;
        }
        for(int v=2;v<=n;v++){
            for(int u=1;u<v;u++){
                if(abs(a[u]-a[v])>d){
                    break;
                }
                m[u][v]=min(m[u][v],abs(a[u]-a[v]));
                q[u][v].push(abs(a[u]-a[v]));
            }
        }
        int ans=0;
        for(int v=2;v<=n;v++){
            for(int u=1;u<v;u++){
                if(abs(a[u]-a[v])>d){
                    break;
                }
                int cnt=0;
                while(q[u][v].size()){
                    int k=q[u][v].front();
                    q[u][v].pop();
                    if(k==m[u][v]){
                        cnt++;
                        if(cnt>2){
                            break;
                        }
                    }
                }
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
