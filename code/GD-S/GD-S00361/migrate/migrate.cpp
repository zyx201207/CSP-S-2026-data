#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		long long sx;
		cin>>sx;
		vector<long long> dist;
		dist.push_back(0);
		for(int i=2;i<=n;i++){
			long long x;
			cin>>x;
			dist.push_back(x-sx); 
		}
		vector<int> last;
		for(int i=1;i<=n;i++){
			int it=upper_bound(dist.begin(),dist.end(),d+dist[i-1])-dist.begin();
			last.push_back(it);
		}
		long long ans=0;
		for(int i=1;i<n-2;i++){
			int it=last[i-1];
			if(it==i){
				continue;
			}
			if(it==i+1){
				continue;
			}
			if(it==i+2){
				int la=last[it-2];
				ans+=la-it;
				continue;
			}
			int la1=last[it-2];
			int la2=last[it-3];
			ans+=la1-la2; 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
