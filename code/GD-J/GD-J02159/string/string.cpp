#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct zfc {
	long long a;
	char c;
} a[N];
long long n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0; i<n; i++) {
		scanf("%lld",&a[i].a);
		cin>>a[i].c;
	}
	unsigned long long num=0;
	int j=n-1,i=0;
	while(1) {
		if(i>n||j<0||i>j) break;
		if(a[i].c==a[j].c) {
			if(a[i].a==a[j].a) {
				i++;
				j--;
			} else if(a[i].a>a[j].a) {
				a[i].a-=a[j].a;
				j--;
			} else if(a[i].a<a[j].a) {
				a[j].a-=a[i].a;
				i++;
			}
		} else if(a[i].c!=a[j].c) {
			if(a[i].a==a[j].a) {
				num+=a[i].a;
				i++;
				j--;
			} else if(a[i].a>a[j].a) {
				num+=a[j].a;
				a[i].a-=a[j].a;
				j--;
			} else if(a[i].a<a[j].a) {
				num+=a[i].a;
				a[j].a-=a[i].a;
				i++;
			}
		}
	}
	printf("%lld",num);
	return 0;
}
