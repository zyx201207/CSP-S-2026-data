#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,minn=LONG_LONG_MAX;
int vis[500005];
struct station{
	int cnt,time;
	vector<int> son;//point that's connected
	int st[25];//p[a].st[b]:time needed to switch to line b;
	bool line[25]={0};
};station p[500005];
void dfs(int x,int y,ll ans,int lst){
//	cout<<ans<<endl;
	vis[x]=1;
	if(x==y){
		minn=min(minn,ans+p[x].time+p[x].st[lst]);
		return;
	}
	for(int i=0;i<int(p[x].son.size());i++){
		int u=p[x].son[i];
		if(vis[u]) continue;
		if(p[u].line[lst]){
			dfs(u,y,ans,lst);
			vis[u]=0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(p[u].line[i]&&p[x].line[i]){
					dfs(u,y,ans+p[x].st[i]+p[x].st[lst],i);
					vis[u]=0;
					break;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>p[i].time;
	int k,x[500005],t[500005];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j]>>t[j];
			p[x[j]].st[i]=t[j];
			p[x[j]].line[i]=1;
			if(j>1){
				p[x[j]].son.push_back(x[j-1]);
				p[x[j-1]].son.push_back(x[j]);
			}
		}
	}
	int st,end;
	for(int i=1;i<=q;i++){
		minn=LONG_LONG_MAX;
		cin>>st>>end;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++)
			if(p[st].line[j])
				dfs(st,end,p[st].time+p[st].st[j],j);
		cout<<minn<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
