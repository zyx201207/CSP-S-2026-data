#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,m,x[N],c,d,q,t,s[N],dis[N],ans,tp;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		int m=0;
		cin>>n>>d;
		for(int j=1; j<=n; j++) {
			cin>>x[j];
			if(j>=2) {
				dis[j]=x[j]-x[j-1];
				s[j]=dis[j]+s[j-1];
			}
			if(j==2) {
				tp==x[2]-x[1];
			}
			if(x[j]-x[j-1]!=tp) {
				tp=0;
			}
		}
		if(x[n]-x[1]<=d) {
			cout<<0<<endl;
		} else if (tp!=0) {
			for(int i=1; i<=n; i++) {
				for(int j=i+2; j<=n; j++) {
					int ob=(s[j]-s[i])/tp;
					int yu=(s[j]-s[i])%tp;
					if(ob==1 && yu!=0 && j!=i+2) {
						ans++;
					} else if(j==i+2 && d>=x[j]-x[i]) {
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		} else {
			cout<<0<<endl;
		}
	}
	return 0;
}
