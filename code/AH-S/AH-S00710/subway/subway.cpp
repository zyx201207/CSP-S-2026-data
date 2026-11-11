#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[5010],a[5010],t[30][5010];
bool vis[30][5010];
int c,n,m,p,q;
int S,T;
int ans=INT_MAX;
vector<int> v[30][5010];
void dfs(int x,int cnt,int sy){
	cout<<x<<" ";
    if(cnt>=ans){
        return ;
    }
    if(x==T){
        ans=min(cnt,ans);
        return ;
    }
    for(int i_=1;i_<=m;i_++){
    for(int i=0;i<v[i_][x].size();i++){
        if(!vis[i_][v[i_][x][i]]){
            vis[i_][v[i_][x][i]]=true;
			if(sy!=i_&&sy!=0){
            dfs(v[i_][x][i],cnt+t[i_][x]+t[sy][x],i_);
			}else{
			dfs(v[i_][x][i],cnt+t[i_][x],i_);
			}
        }
    }
	}
    return ;
}
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>p>>q;
	for(int i=1;i<=n;i++){
        cin>>w[i];
	}
	int k;
	for(int i=1;i<=m;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[i][j];
        }
        for(int j=1;j<=k;j++){
            for(int j_=j+1;j_<=k;j_++){
                v[i][a[j]].push_back(a[j_]);
                v[i][a[j_]].push_back(a[j]);
            }
        }
	}
	while(q--){
        memset(vis,false,sizeof(vis));
        ans=INT_MAX;
        cin>>S>>T;
        cout<<endl;
        vis[1][S]=true;
        dfs(S,0,0);
        ans=ans+w[S]+w[T];
        cout<<ans<<endl;
	}
	return 0;
}
