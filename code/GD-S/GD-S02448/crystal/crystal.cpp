#include <bits/stdc++.h>//超时10~12 19~20 
using namespace std;
bool w;
const int N=500005;
long long n,m,a[N],ans=0,f,z;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	//特殊性质A判定-
	w=true;
	for(int i=1; i<=n; i++) {
		if(a[i]!=i) {
			w=false;
			break;
		}
	}
	if(w) {
		f=z=0;
		for(int j=n-1; j>=1; j--) {
			f+=a[n]-a[j];
			if(f>m) {
				break;
			}
			z++;
		}
		printf("%lld",z+1);
		return 0;
	}
	//特殊性质B判定-
	w=true;
	z=a[2]-a[1];
	for(int i=3; i<=n; i++) {
		if(a[i]-a[i-1]!=z) {
			w=false;
			break;
		}
	}
	if(w) {
		f=z=0;
		for(int j=n-1; j>=1; j--) {
			f+=a[n]-a[j];
			if(f>m) {
				break;
			}
			z++;
		}
		printf("%lld",z+1);
		return 0;
	}
	//朴素判定-
	for(int i=n; i>=1+ans; i--) {
		f=z=0;
		for(int j=i-1; j>=1; j--) {
			f+=a[i]-a[j];
			if(f>m) {
				break;
			}
			z++;
		}
		ans=max(ans,z);
	}
	printf("%lld",ans+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Oct31==Dec25?
