#include <bits/stdc++.h>
using namespace std;
int T[500005];vector<pair<short,int>>pass[500005];vector<int>cross[505];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,a,f,t;unsigned long long ans=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>T[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>a;
			cin>>t;
			pass[a].push_back(make_pair(i,t));
			cross[i].push_back(a);
		}
	}
	while(q--){
		cin>>f>>t;
		ans+=pass[f][0].second+pass[t][0].second;
		cout<<ans+T[f]+T[t]<<"\n";
		ans=0;
	}
	return 0;
} 
