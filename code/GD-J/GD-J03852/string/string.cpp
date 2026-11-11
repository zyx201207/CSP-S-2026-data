#include<bits/stdc++.h>
using namespace std;
struct W {
	long long f;
	char s;
};
int h(long long a,long long b) {
	if(a>b) {
		return a-b;
	}
	if(a==b) {
		return 0;
	}
	if(a<b) {
		return a-b;
	}
	return 0;
}
W k[200005];
char z;
long long l,a[200005],n,ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>z;
		l+=a[i];
		k[i].f=a[i];
		k[i].s=z;
	}
	int i=1,j=n;
	while(i<j) {
		if(k[i].s==k[j].s) {
			long long t=h(k[i].f,k[j].f);
			if(t>0) {
				j--;
				k[i].f=t;
			}
			if(t==0) {
				i++;
				j--;
			}
			if(t<0) {
				i++;
				k[j].f=-t;
			}
		} else {
			long long t=h(k[i].f,k[j].f);
			if(t>0) {
				ans+=k[j].f;
				j--;
				k[i].f=t;
			}
			if(t==0) {
				ans+=k[i].f;
				i++;
				j--;
			}
			if(t<0) {
				ans+=k[i].f;
				i++;
				k[j].f=-t;
			}
		}
	}
	cout<<ans;
	return 0;
}
