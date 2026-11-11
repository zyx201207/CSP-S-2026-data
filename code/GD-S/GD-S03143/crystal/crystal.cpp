#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define F first
#define S second
using namespace std;
const int N=5e5+10;
int n,ans,cnt;
ll m,a[N],cf[N];
int main() {
	wc("crystal");
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cf[i]=cf[i-1]+a[i]-a[i-1];
	cnt=ans=1;
	int fi=1;
	for(int i=2;i<=n;i++) {
		while(cnt*(a[i]-a[i-1])>m) {
			cnt--;
			m+=a[i-1]-a[fi];
			fi++;
		} 
		m-=cnt*(a[i]-a[i-1]);
		cnt++;
		//cout<<cnt<<' '<<'\n';
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
