#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
vector<long long> w;
vector<long long> a;
vector<long long> t;
vector<pair<long long,long long>> r;
long long pos[10000001];
vector<long long> meet;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		long long u;
		cin>>u;
		w.push_back(u);
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		while(k--){
			long long u,v;
			cin>>u>>v;
			a.push_back(u);
			if(pos[u]!=0){
				meet.push_back(u);
			}
			else{
				pos[u]++;
			}
			t.push_back(v);
		}
	}
	for(int i=1;i<=q;i++){
		long long u,v;
		cin>>u>>v;
		r.push_back({u,v});
	}
	
	return 0;
}

