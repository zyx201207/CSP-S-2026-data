#include<bits/stdc++.h>
using namespace std;
int ent[500005],sum=0;
struct edge{
	int to;
	int next;
	int pay;
}e[500005];
struct si{
	int a;
	int t;
};
int head[500005];
int cnt=1;
void ad(si u,si v){
	e[cnt].pay=u.t+v.t;
	e[cnt].to=v.a;
	e[cnt].next=head[u.a];
	head[u.a]=cnt;
	cnt++;
}
bool flag[500005];
void dfs(int nst,int des,int tim){
	if(nst==des){
		sum=min(sum,tim+ent[des]);
		return;
	}
	for(int i=head[nst];i!=-1;i=e[i].next){
		int v=e[i].to;
		if(!flag[v]){
			flag[v]=1;
			dfs(v,des,tim+e[i].pay);
			flag[v]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	int c,m,n,d,q;
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ent[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<si> site;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			si a1={a,t};
			site.push_back(a1);
		}
		for(int j=0;j<site.size();j++){
			for(int k=0;k<site.size();k++){
				if(j==k)continue;
				ad(site[j],site[k]);
				ad(site[k],site[j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		sum=0;
		memset(flag,0,sizeof(flag));
		flag[u]=1;
		dfs(u,v,ent[u]);
		cout<<sum<<"\n";
	}
	return 0;
}
