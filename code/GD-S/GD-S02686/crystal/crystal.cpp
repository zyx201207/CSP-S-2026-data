#include<bits/stdc++.h>
using namespace std;
long long a[555555];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	long long kx=1,le=1,xm=0;
	long long ans=1;
	for(int i=2;i<=n;i++){
		xm+=(a[i]-a[i-1])*kx;
		kx++;
		while(xm>m){
			xm-=a[i]-a[le];
			le++;
			kx--;
		}
		ans=max(ans,kx);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
