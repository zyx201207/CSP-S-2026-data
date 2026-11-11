#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	int l=1,r=n;
	int mid;
	while(l<r){
		mid=(l+r+1)>>1;
		bool f=0;
		for(int i=mid;i<=n;i++)
			if(mid*a[i]-q[i]+q[i-mid]<=m){
				f=1;break;
			}
		if(f)l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
