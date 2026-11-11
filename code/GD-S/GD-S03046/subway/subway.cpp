#include <bits/stdc++.h>
//#include <-foncepts>
using namespace std;
vector<pair<int,long long>> e[20000500];
long long w[500005],c,n,m,d,p,k[500005],t,an[20000500],x,y;
int a[2];
void dfs(vector<pair<int,long long>> u, int fa){
	for( pair<int,long long> v : u)
	{
		if(v.first==fa)continue;
		
		dfs(e[v.first],v.first);
		an[fa]=min(an[fa]+v.second,an[v.first]);
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	a[1]=0;
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			a[0]=a[1];
			cin>>a[1]>>t;
			an[a[1]]=1000000000;
			e[a[0]*(n+i)].push_back({a[1]*(n+i),0});
			e[a[1]*(n+i)].push_back({a[0]*(n+i),0});
			e[a[1]*(n+i)].push_back({a[1],t});
			e[a[1]].push_back({a[1]*(n+i),t});
		}
	}
	while(p--){
		cin>>x>>y;
		dfs(e[x],0);
		cout<<an[y]+w[x]+w[y]<<endl;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				an[j*(n+1)]=1000000000;
			}
		}
	}
	

	return 0;
} 
