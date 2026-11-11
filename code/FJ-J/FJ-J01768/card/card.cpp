#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	vector<long long> a;
	
	long long ans[4]= {0,0,0,0};
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		int ls;
		cin>>ls;
		a.push_back(ls);
	}
	for(int i=0; i<n; i++) {
		vector<long long> g(n,-1);
		for(int j=i; j<n; j++) {
			g[j]=a[j];
			if(g.size()>1) {
				for(int k=0; k<j; k++) {
					if(g[k]==g[j]) {
						for(int e=k; e<j; e++) {
							g[e]=-1;
						}
					}
				}
			}
		}
		for(int j=1; j<=m; j++) {
			for(int k=0; k<g.size(); k++) {
				if(g[k]==j&&g[k]>0) {
					ans[j]++;
				}
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
