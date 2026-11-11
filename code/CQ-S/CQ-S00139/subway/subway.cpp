#include<bits/stdc++.h>
using namespace std;
struct f{
	int id,t;
}z[500005];
vector<int>a1[50005];
vector<int>a2[50005];
int s[50005][50005];
int ans;
int v[500005];
int f1[500005],t;
void dfs(int u,int v){
	if(u==v){
		f1[++t]=ans;
		return;
	}
	for(int i=1;i<=a1[u].size();i++){
		int x=a1[u][i],int y=a2[u][i];
		if(!v[x]){
			ans+=y;
			v[x]=1;
			dfs(x,v);
			ans-=y;
			v[x]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int id,ss,zs,zzd,p;
	cin>>id>>ss>>zs>>zzd>>p;
	for(int i=1;i<=zs;i++)
		cin>>z[i].id;
	for(int i=1;i<=ss;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>s[i][j]>>z[s[i][j]].t;
		for(int j=1;j<=k;j++)
			for(int o=1;o<=k;o++)
				if(o!=j){
					a1[j].push_back(o);
					a2[j].push_back(0);
					a1[o].push_back(j);
					a2[o].push_back(0);
				}
				else{
					a1[j].push_back(o);
					a2[j].push_back(z[o].t);
					a1[o].push_back(j);
					a2[o].push_back(z[j].t);
				}
	}
	for(int i=1;i<=p;i++){
		memset(f1,0,sizeof(f1));
		ans=t=0;
		int u,v;
		cin>>u>>v;
		for(int i=1;i<=t;i++)
			ans=min(ans,f1[i]);
		cout<<ans<<endl;
	}
	return 0;
}
