#include<bits/stdc++.h>
using namespace std;
long long a[500010],h[500010];
int n;
long long m;
bool c(int l){
	for(int i=1;i<=n-l+1;i++){
		if(a[i+l-1]*l-h[i+l-1]+h[i-1]<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)h[i]=h[i-1]+a[i];
	int l=1,r=n,mid=(l+r)/2;
	while(l<r){
		mid=(l+r+1)/2;
		if(c(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
