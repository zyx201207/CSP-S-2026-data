#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll
using VI=vector<int>;
using PI=pair<int,int>;
const ll N=1e6+5,inf=1e12;
int n,m,now,dep[N];VI g[N];
void dfs(int x,int fat,int far){
	dep[x]=0;
	for(int y:g[x]){
		if(y==fat)continue;
		dfs(y,x,far);
		dep[x]=max(dep[x],dep[y]+1);
	}
	if(dep[x]==far){now--;}
}
bool check(int far){
	now=m;dfs(1,0,far);
	return now>=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;while(T--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(m>=n){cout<<"0\n";continue;}
		int l=0,r=n,ans=0;
		/*while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}*/
		cout<<(n-m)/2<<"\n";
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
