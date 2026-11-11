#include<bits/stdc++.h>
using namespace std;
long long a[5000001],b[5000001],m;
int f(int t){
	int l=1,r=t;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[t]*(t-mid+1)-(b[t]-b[mid-1])>m) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int j=f(i);
		mx=max(mx,i-j+1);
	}
	cout<<mx;
	return 0;
}
