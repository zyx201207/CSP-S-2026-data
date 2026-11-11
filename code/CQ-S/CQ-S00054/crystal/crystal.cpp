#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500001],ans=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		long long mm=m,anns=1;
		for(int j=i-1; j>0; j--) {
			mm-=(a[i]-a[j]);
			anns++;
			if(mm<0) {
				ans=max(ans,anns-1);
				break;
			} else if(mm==0) {
				ans=max(ans,anns);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
