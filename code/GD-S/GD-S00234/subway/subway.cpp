#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+10;
const int inf=INT_MAX;
long long c,n,m,d,q;
long long w[N];
vector<int> sub[N];
vector<int> g[N];
map<pair<int,int>,int> t;
int find(int x,int y,int l){
	for(int u:sub[l]){
		for(int v:sub[l]){
			if(u==x&&v==y)  return l;
		}
	}
	return -1;
}
int check(int x,int y){
	for(int i=1;i<=n;i++){
		int f=find(x,y,i);
		if(f!=-1)  return f;
	}
	return -1;
}
long long dfs(int x,int y){
	int line=check(x,y);
	if(line!=-1){
		return t[{x,line}]+t[{y,line}];
	}
	long long res=inf;
	for(int i=1;i<=n;i++){
		int c1=check(x,i),c2=check(y,i);
		if(c1!=-1&&c2!=-1){
			res=min(res,dfs(x,i)+dfs(i,y));
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)  cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a1,t1;
			cin>>a1>>t1;
			t[{a1,i}]=t1;
			sub[i].push_back(a1);
			g[a1].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dfs(x,y)<<endl;
	}
	return 0;
}

