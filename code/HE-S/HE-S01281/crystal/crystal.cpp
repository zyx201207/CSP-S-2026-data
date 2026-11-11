#include<iostream>
#define ll long long
using namespace std;
const int n=5e5+1;
ll m,a[n],d[n],cnt; 
int l=1,r=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		d[i]=a[i]-a[i-1];
	cnt=d[1];
	while(1){
		while(r<n && (cnt<<1) + d[r+1]<=m)
			cnt=(cnt<<1)+d[r++];
		ans=max(ans,r-l+1);
		if(r==n)
			break;
		while(l<r && (cnt<<1) + d[r+1]>m)
			cnt=cnt-d[l+1]-a[r];
		if(l==r)
			break;
	}
	cout<<ans;
	return 0;
} 
