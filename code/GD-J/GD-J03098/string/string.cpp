#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N];
ll b[N],cnt=1,ans;
char c[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		b[i]=cnt;
		cnt+=a[i];
	}
	b[n+1]=cnt;
	int l=1,r=n;
	ll lst=1;
	
//	for(int i=1;i<=n+1;i++) cout<<b[i]<<" ";
//	cout<<"\n";
	
	while(l<=r) {
		ll len=cnt-b[r];
		int t=upper_bound(b+1,b+1+n,len)-b-1;
//		cout<<r<<" "<<len<<" "<<lst<<"\n";
		for( ;l<=t;l++) {
			if(c[l]!=c[r]) {
//				cout<<b[l+1]-1<<" "<<b[l]-1<<"\n";
				ans+=min(len,b[l+1]-1)-max(lst,b[l]-1)+1;
			}
		}
		lst=len+1;
		r--;
	}
	cout<<ans;
	
	return 0;
}
