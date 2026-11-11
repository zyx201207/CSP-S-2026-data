#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	long long l=1,r=1;
	long long ans=0;
	for(l=1;l<=n;l++){
		while(r<=n&&((r-l)*a[r]-(b[r-1]-b[l-1]))<=m)r++;
		r--;
		//cout<<l<<" "<<r<<"\n";
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
