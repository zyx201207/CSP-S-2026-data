#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q,w[500005],k,t[5005][5005],T;
struct lxc{
	long long x,val;
};
vector<long long> a[500005];
queue<lxc> q;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++) {
		cin >> k;
		int sr1,sr2,sa[500005],st[500005];
		for(int j=1;j<=k;j++) {
			cin >> sa[j] >> t[i][j];
			T=t[i][j];
		}
		for(int j=1;j<k;j++) {
			for(int o=j+1;o<=k;o++) {
				a[j].push_back(sa[o]);
			}
		}
	}
	if(c>=7&&c<=11) {
		while(Q--) {
			int sr1,sr2,ans=INT_MAX;
			cin >> sr1 >> sr2;
			q.push({sr1,w[sr1]+w[sr2]});
			while(!q.empty()) {
				lxc p=q.front();
				q.pop();
				if(p.x==sr2) {
					if(p.val<ans) ans=p.val;
				}
				int len=a[p.x].size();
				for(int i=0;i<len;i++) {
					q.push({a[p.x][i],p.val+t[p.x][p.x]+t[p.x][a[p.x][i]]});
				}
			}
			cout << ans << endl;
		}	
	}
	else if(c>=12&&c<=19) {
		while(Q--) {
			int sr1,sr2,ans=INT_MAX;
			cin >> sr1 >> sr2;
			q.push({sr1,w[sr1]+w[sr2]});
			while(!q.empty()) {
				lxc p=q.front();
				q.pop();
				if(p.x==sr2) {
					if(p.val<ans) ans=p.val;
				}
				int len=a[p.x].size();
				for(int i=0;i<len;i++) {
					q.push({a[p.x][i],p.val+2*T});
				}
			}
			cout << ans << endl;
		}		
	}
	else {
		while(Q--) {
			int sr1,sr2,ans=INT_MAX;
			cin >> sr1 >> sr2;
			q.push({sr1,w[sr1]+w[sr2]});
			while(!q.empty()) {
				lxc p=q.front();
				q.pop();
				if(p.x==sr2) {
					if(p.val<ans) ans=p.val;
				}
				int len=a[p.x].size();
				for(int i=0;i<len;i++) {
					q.push({a[p.x][i],p.val+t[p.x][p.x]+t[p.x][a[p.x][i]]});
				}
			}
			cout << ans << endl;
		}			
	}
	return 0;
}