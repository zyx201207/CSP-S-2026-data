//GZ-S00433 遵义市南白中学 辜煜祺
#include <bits/stdc++.h>
using namespace std;
long long m,n,a[50005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n=0) {
		cout<<0;
		return 0;
	}
	long long maxx=1;
	if(m==0) {
		for(int i=2; i<=n; i++) {
			int tot=1;
			if(a[i]==a[i-1]) {
				for(int st=i; a[st-1]==a[st]; st++)tot++;
			}
			maxx=maxx>tot?maxx:tot;
		}
		cout<<maxx;
		return 0;
	}
	if(((long long)((long long)sqrt(m*8+1)-1)/2)>n-1)cout<<n;
	else cout<<((long long)sqrt(1+8*m)-1)/2+1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

