#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool e[200005];
long long b[200005];
long long tot = 0;
bool cmp(long long x,long long y){
	return x >= y;
}
void qpr(int xb,int cs,long long num) {
//	cout<<xb<<" "<<num<<endl;
	if(cs == 0) {
		tot = max(num,tot);
		b[xb] = tot;
		return;
	} else {
		for(int i = xb; i<=n; i++) {
			if(b[i] != 0) {
				qpr(i,0,b[i]);
			} else if(e[i]==0) {
				e[i] = 1;
				qpr(i+1,cs-1,(num==0?a[i]:(num&a[i])));
				e[i] = 0;
			}
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool q = 1,k = 1;
	for(int i = 1; i<=n; i++) {
		scanf("%lld",&a[i]);
		if(i >= 2 && a[i]-a[i-1] != 1){
			q = 0;
		}
		if(i >= 1 && pow(2,i)-1 != a[i]){
			k = 0;
		}
	}
	sort(a+1,a+1+n,cmp);
	if(m == 1) {
		sort(a+1,a+1+n,cmp);
		printf("%lld",a[n]);
	
	}else if(q){
		int x = a[m];
		for(int i = m;i >= 0;i--){
			a[i] = (a[i]&x);
		}
		cout<<x<<endl;
	}else if(k){
		int x = a[m];
		cout<<x<<endl;
	} else {
		qpr(1,m,0);
		cout<<tot<<endl;
	}
	return 0;
}
