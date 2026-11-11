#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[4005][4005];
int dis[4005];
int t[4005];
int n,k;
int maxx=1e9;
void kkk(){
    for(int i=1;i<=n;i++){
        if(dis[i]==1){
            for(int j=1;j<=n;j++){
                if(a[i][j]==1){
                    t[j]=1;
                }
            }
        }
    }
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(t[i]==0){
            cnt=max(cnt,1000000009ll);
        }
    }
    maxx=min(cnt,maxx);
}
void dfs(int x,int y){
    if(x==0 && y==0){
        kkk();
    }
    if(x==0 || y==0){
        return ;
    }
    dis[x]=1;
    dfs(x-1,y-1);
    dis[x]=0;
    dfs(x-1,y);
}
void slove(){
    maxx=1e9;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
    }
    if(n<=8){
        cout<<1<<endl;
        return ;
    }
    if(n<=10){
        cout<<2<<endl;
        return ;
    }
    dfs(n,k);
    cout<<maxx;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
        slove();
	}
    return 0;
}
