#include<bits/stdc++.h>
using namespace std;
struct node {
	long long num;
	char s;
};
long long m,ans,n,k;
node a[200005],b[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0; i<n; i++) {
		scanf("%lld%s",&a[i].num,&a[i].s);
		m+=a[i].num;
	}
	m/=2;
	for(long long i=0; i<n; i++) {
		if(!m)break;
		if(m>=a[i].num) {
			m-=a[i].num;
			b[k].num=a[i].num;
			b[k].s=a[i].s;
			k++;
		} else {
			b[k].num=m;
			b[k].s=a[i].s;
			m=0;
			k++;
		}
	}
	for(long long i=0,j=n-1; i<k;) {
		if(b[i].s!=a[j].s) {
			if(b[i].num>a[j].num) {
				ans+=a[j].num;
				b[i].num-=a[j].num;
				j--;
			} else if(b[i].num<a[j].num) {
				ans+=b[i].num;
				a[j].num-=b[i].num;
				i++;
			} else {
				ans+=b[i].num;
				i++,j--;
			}
		} else {
			if(b[i].num>a[j].num) {
				b[i].num-=a[j].num;
				j--;
			} else if(b[i].num<a[j].num) {
				a[j].num-=b[i].num;
				i++;
			} else {
				i++,j--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
