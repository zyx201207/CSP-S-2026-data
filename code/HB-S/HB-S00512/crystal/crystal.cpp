#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
bool pd(int x){
	int d=0,num=0;
	for(int i=1;i<=n;i++){
		num+=max(d,x-a[i]);
	}
	return num<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1,tnt=a[2]-a[1],g=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
		if(a[i]-a[i-1]!=tnt)g=0;
	}
	if(f){
		for(int i=n;i>=1;i--){
			if(i*(i-1)/2<=m){
				cout<<i;
				return 0;
			}
		}
	}
	if(g){
		for(int i=n;i>=1;i--){
			if(((a[i]-tnt+a[1])*((a[i]-tnt-a[1])/tnt+1))/2<=m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	int l=1,r=a[n],mid;
	while(l<=r){
		mid=(l+r)/2;
		if(pd(mid))l=mid+1;
		else r=mid-1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(a[i]<=r)ans++;
	cout<<ans;
	return 0;
}
