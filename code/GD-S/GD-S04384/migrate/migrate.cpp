#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N(2e6+5);
int c,t,n,d,ans;
int x[N];
vector<int>v;
void dfs(int c,int s,int g){
	if(c==g) return void(v.push_back(s));
	for(int i=c+1;i<=n and x[i]-x[c]<=d;++i) dfs(i,s+1,g);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(;t--;ans=0){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				v.clear();
				dfs(i,0,j);
				sort(v.begin(),v.end());
				if(v.size()<3) continue;
				if(v[0]==v[1] and v[1]!=v[2]) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
