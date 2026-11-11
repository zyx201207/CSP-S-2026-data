#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct Nova {
	int id,p;
};
Nova t[N];
bool cmp(Nova a,Nova b){
	return a.p>b.p;
}
int n,m;
int a[N],s[N],f[N];
vector<int>g[N];
void dfs(int x,int fa){
	f[x]=s[x];
	for(int i=0;i<(int)g[x].size();i++){
		int y=g[x][i];
		if(y==fa)continue;
		dfs(y,x);
		f[x]+=f[y];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]].p=i;
		s[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		t[i].id=i;
	}
	sort(t+1,t+1+m,cmp);
	for(int i=2;i<=m;i++){
		g[t[i].id].push_back(a[t[i].p+1]);
		g[a[t[i].p+1]].push_back(t[i].id);
	}
	dfs(t[1].id,0);
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
	return 0;
}
