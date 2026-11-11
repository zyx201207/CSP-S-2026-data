#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using LL=long long;
LL a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	int num=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		num+=a[i];
	}
	sort(a+1,a+n+1);
	int num1=num/n;
	if((num-num1*n)>((num1+1)*n-num))num1++;
	LL ans=1e9,id;
	for(int i=1; i<=n; i++) {
		if(abs(a[i]-num1)<abs(num1-ans)) {
			ans=a[i],id=i;
		}
		if(i-id>2)break;
	}
	for(int i=id; i>=1; i--) {
		if(m-(ans-a[i])>=0) {
			m-=(ans-a[i]);
			a[i]=ans;
		} else {
			break;
		}
	}
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(a[i]==ans)cnt++;
	}
	while(m-id>=0) {
		if(m-cnt*(a[id+1]-a[id])>=0) {
			m-=cnt*(a[id+1]-a[id]);
			cnt++;
			id++;
		}
		if(cnt==n) {
			cout<<n;
			return 0;
		}
	}
	cout<<cnt;
}
