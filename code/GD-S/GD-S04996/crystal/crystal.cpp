#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a[600001],ans,cnt,j,o,k;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--) {
		o=m,cnt=0;
		for(j=i-1;j>=1;j--) {
			k=a[i]-a[j];
			if(a[i]-a[j]<=o) {
				o-=a[i]-a[j];
				cnt++;
			} 
			else break;
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
}
