#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=5e5+5;
int n,ans=1;
ll a[N],w[N];
unsigned long long qc[N],qc2[N];
unsigned long long m;

int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for (int i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		w[i]=a[i]-a[i-1];
	for (int i=1;i<=n;i++)
		qc[i]=qc[i-1]+w[i];
	for (int i=1;i<=n;i++)
		qc2[i]=qc2[i-1]+qc[i];
	int l=1,r=2;
	while (l<=r && r<=n) {
		if ((r-l)*qc[r]-(qc2[r-1]-qc2[l-1])<=m) {
			++ans;
			++r;
		}
		else {
			++l; ++r;
		}
	}
	printf("%d",ans);
	return 0;
}
