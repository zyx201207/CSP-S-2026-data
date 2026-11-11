#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005],m;
bool check(int l,int r,int d){
	return (m-((r-l+1)*d-b[r]+b[l-1])>=0);
}
int f(int l,int r,int d){
	int L=l,R=r;
	while(L+1<R)
	{
		int mid=(L+R)/2;
		if(check(mid,r,d))
			R=mid-1;
		else
			L=mid;
	}
	return (check(R,r,d) ? r-R+1 : r-R);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	if(n==1)
		cout<<1;
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
		b[i]=b[i-1]+a[i];
	for(int i=1; i<=n; i++)
		ans=max(ans,f(1,i,a[i]));
	cout<<ans;
	return 0;
} 
