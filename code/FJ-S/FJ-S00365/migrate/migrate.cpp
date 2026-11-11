#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T,n,d,ans;
int a[N],w[N];
queue<int>q,p;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)w[i]=0;
		q.push(1);
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			if(i>1&&a[i]-a[i-1]>d) {
				q.push(i);
				w[i-1]=i-1;
			}
			p.push(i);
			while((p.front()<i&&a[p.front()]+d<a[i])||w[p.front()]==1e9) {
				if(w[p.front()]==0)w[p.front()]=i-1;
				p.pop();
			}
		}
		while(!p.empty()) {
			if(w[p.front()]==0)w[p.front()]=n;
			else w[p.front()]==p.front();
			p.pop();
		}
		q.push(n+1);
		while(!q.empty()) {
			int s=q.front();
			q.pop();
			if(q.empty())break;
			int t=q.front()-1;
			if(t-s<3)continue;
			ans=0;
			for(int i=s; i<=t; i++) {
				int z=w[i];
				if(w[z-1]==w[z]&&w[z-2]!=w[z]) {
					ans++;
				} else if(w[z-1]==z+1&&w[z-2]!=z+1) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
