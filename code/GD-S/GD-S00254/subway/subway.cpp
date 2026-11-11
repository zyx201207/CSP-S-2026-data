#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],xr,yr,ans,minn=numeric_limits<int>::max();
vector<int> e[500005];
int xct[500005][20],cnt[500005];
void dfs(int now,int end,int sum,int fa,int xc){
	int xy;
	if(now==end){
		minn=min(minn,sum);
		return ;
	}
	for(int i=0;i<e[now].size();i++){
		int v=e[now][i];
		if(v==fa){
			continue;
		}
		for(int i=1;i<=cnt[v];i++){
			if(xct[xc][i]==xc){
				dfs(v,end,sum,now,xc);
			}
			for(int j=1;j<=k[xc];j++){
				if(a[xc][j]==now){
					xy=t[xc][j];
				}
			}
			for(int i=1;i<=cnt[now];i++){
				if(xct[now][i]==xc){
					continue;
				}
				if(xct[xc][i]!=xc){
					dfs(v,end,sum+xy+t[xct[now][i]][i],now,xct[xc][i]);
				}
			}
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back(a[i][j-1]);
			e[a[i][j-1]].push_back(a[i][j]);
			xct[a[i][j]][++cnt[a[i][j]]]=i;
		}
	}
	while(q--){
		cin>>xr>>yr;
		ans=w[xr]+w[yr];
		for(int i=1;i<=cnt[xr];i++){
			minn=numeric_limits<int>::max();
			dfs(xr,yr,0,0,xct[xr][i]);
		}
		cout<<minn<<endl;
	}
	return 0;
}
