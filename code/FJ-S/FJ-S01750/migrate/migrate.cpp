#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],p=-1e9;
int dfs(int u,int t,int val,int s) {
	if(u==t) return val;
	int cnt=INT_MAX,ans=0;
	for(int i=u+1;i<=t;++i) {
		if(abs(a[i]-a[u])<=d) {
			int o=dfs(i,t,val+1,s);
			if(o<cnt) {
			cnt=o,ans=1;
			}
			else if(o==cnt) ++ans;
		}
	}
	if(u==s)return ans;
	return cnt;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		int dl=0;
		dfs(1,5,0,1);
		for(int i=1;i<n;++i) 
			for(int j=i+1;j<=n;++j){
			if(dfs(i,j,0,i)==2)++dl;
			}
		cout<<dl<<"\n";
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
