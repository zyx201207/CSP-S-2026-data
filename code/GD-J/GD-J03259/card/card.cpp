#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(x) freopen(x".in","r",stdin);
#define fop(x) freopen(x".out","w",stdout);
#define IO(x) fin(x)fop(x)
stack<ll>e;
int n,m,a[500005],ans[300005],use[300005];
int main() {
	IO("card")
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) {
			use[j]=0;
		}
		while(!e.empty()) {
			e.pop();
		}
		for(int j=i; j<n; j++) {
			e.push(a[j]);
			use[a[j]-1]++;
			if(use[a[j]-1]==1)ans[a[j]-1]++;
			if(use[a[j]-1]==2) {
				e.pop();
				while(e.top()!=a[j]) {
					if(use[e.top()-1]-1==0)ans[e.top()-1]--;
					e.pop();
				}
			}
		}
	}
	for(int i=0; i<m; i++) {
		cout<<ans[i]<<" ";
	}
}
