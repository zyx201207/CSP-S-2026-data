#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	long long n,a[200005];char c[200005];
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long l=1,r=n,ans=0;
	while(l<r){
		int p=min(a[l],a[r]);
		if (c[l]!=c[r]) ans+=p;
		a[l]=a[l]-p;a[r]=a[r]-p;
		if (a[l]==0) l++;
		if (a[r]==0) r--;
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
}
