#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
long long c,n,m,de,q,k,z,x,y,a[maxn],d[maxn],ans,s,e;
vector<array<long long,2>> v[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>m>>n>>de>>q;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=m;i++){
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>x>>y;
			z++;
			v[n+z].push_back({y,x});
			v[x].push_back({y,n+z});
			if(j==1) continue;
			v[n+z].push_back({0,n+z-1});
			v[n+z-1].push_back({0,n+z});
		}
	}
	while(q--){
		cin>>s>>e;
		ans = a[s]+a[e];
		priority_queue<array<long long,2>,vector<array<long long,2>>,greater<array<long long,2>>> q;
		fill(d,d+n+z+1,1e18);
		for(q.push({0ll,s});q.size();){
			array<long long,2> t = q.top();
			q.pop();
			long long w = t[0],x = t[1];
			if(w<d[x]){
//				cout<<x<<" "<<w<<"\n";
				d[x] = w;
				for(array<long long,2> i : v[x]){
					q.push({w+i[0],i[1]});
				}
			} 
		}
		cout<<ans+d[e]<<"\n";
	}
	return 0;
}
