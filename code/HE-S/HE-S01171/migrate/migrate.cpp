#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5;
LL c,t;
LL n,d;
LL q[N];
LL dist[N];
stack<LL> a;
LL nw[N];
int main() {
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int ans=0;
		cin>>n>>d;
		for(LL i=0; i<n; i++) {
			cin>>q[i];
		}
		a.push(0);
		int dt=0;
		while(!a.empty()) {
			LL l=a.top();
			a.pop();
			for(LL i=1; i<=n; i++) {
				
				if(q[l+i]-q[l]<=d) {
					a.push(q[i]);
					dt=dist[l]+1;
				
					if(1==1) {
						dist[i]=dt;
						
					} else {
						
						if(dt<dist[i]) {
							
							nw[i]=0;
							dist[i]=dt;
							
						} else if(dt==dist[i]) {
							nw[i]++;
						} 
					}
				}
			}
			
		}
		for(LL i=0; i<n; i++) {
			if(q[i]==2) {
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
