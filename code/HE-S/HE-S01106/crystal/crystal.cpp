#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,c,ans=1,sum=1;
int a[N],b[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		sort(a,a+n+1);
		b[i]=a[i+1]-a[i];
	}
	if(b[n-1]==0)ans++;
	for(int i=1; i<n; i++) {
		c=b[i+1];
		if(b[i]==0) {
			sum++;
		} else {

			if(b[i]==m) {
				ans++;
			}
			if(c+b[i]==m) {
				ans+=2;
			} else {
				c=b[i]+b[i+1];
			}
		}
	}
	if(sum>ans)  cout<<sum;
	else cout<<ans;

	return 0;
}
