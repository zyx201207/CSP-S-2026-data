#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum,b[500005],ans,minn=0x3f3f3f3f,x=0,id,flag;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(!flag) {
		for(int i=1; i<=n; i++) {
			sum+=abs(a[n/2]-a[i]);
			if(sum>m) {
				cout<<ans;
				return 0;
			}
			ans++;
		}
	}
	sum/=n;
	for(int i=1; i<=n; i++) {
		if(abs(a[i]-sum)*1ll<minn) {
			minn=abs(a[i]-sum)*1ll;
			x=a[i];
			id=i;
		}
	}
	for(int i=1; i<=n; i++) {
		b[i]=(x-a[i]);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		sum+=b[i];
		if(sum>m){
			cout<<ans;
			return 0;
		}
		ans++;
	}
	cout<<ans;



	return 0;
}
