#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,n,a[N];
inline bool check(int x){
	long long sum=0;
	for(int i=1;i<=x;i++)sum+=a[x]-a[i];
	if(sum<=m)return 1;
	for(int i=2;i<=n-x;i++){
		sum=sum-a[i+x-1]+a[i-1]+x*(a[i+x]-a[i+x-1]);
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}