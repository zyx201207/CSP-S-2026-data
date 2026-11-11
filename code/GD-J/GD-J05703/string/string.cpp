#include <bits/stdc++.h>
using namespace std;

struct node {
	long long v;
	char m;
}f[200010];
long long n;
long long ans;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>f[i].v>>f[i].m;
		if(f[i-1].m==f[i].m ) {
			f[i-1].v=f[i-1].v+f[i].v;
			i--;
			n--;
		}
	}
	
	for(int i=1,j=n;i<=n/2&&j>=n/2;i++,j--) {
		if(i==j) break;
		if(f[i].m==f[j].m) {
			if(f[i].v==f[j].v) {
				continue;
			}
			else {
				ans=ans+max(f[i].v,f[j].v)-min(f[i].v,f[j].v);
			}
		}
		else {
			ans=ans+max(f[i].v ,f[j].v );
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
