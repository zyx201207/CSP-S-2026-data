#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],b[N];
bool pd(int x){
	long long num=0ll,mn=1e18;
	for(int i=2;i<=x;i++)num+=(i-1)*b[i];
	for(int i=x+1;i<=n;i++){
		mn=min(mn,num);
		num-=(a[i-1]-a[i-x]);
		num+=(x-1)*b[i];
	}
	return min(mn,num)<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1ll)>>1;
		if(pd(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
}