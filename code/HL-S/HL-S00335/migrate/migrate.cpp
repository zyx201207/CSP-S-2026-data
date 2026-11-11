#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long dis[5005][5005];
long long vis[5005][5005];
const int INF=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        memset(dis,0x3f,sizeof(dis));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                vis[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=a[j]-a[i];
                if(dis[i][j]<=d) dis[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=i;k<=j;k++){
                    if(dis[i][j]==dis[i][k]+dis[k][j]){
                        vis[i][j]++;
                    }
                    else if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        vis[i][j]=0;
                    }
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(vis[i][j]+1==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
	return 0;
}
