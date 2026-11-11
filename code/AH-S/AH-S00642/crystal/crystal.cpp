#include<bits/stdc++.h>
#define int long long
using namespace std;
//priority_queue
//permutation
const int N=5e5+10;
int a[N],b[N],s[N],s2[N];
int n,m;
int sol(int x,int y){
	int c=s2[x]-s2[y+1];
	int t=s[y+1];
	return c-(y-x+1)*t;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)s[i]=s[i+1]+a[i]-a[i-1],s2[i]=s2[i+1]+s[i];
	int ans=0;
	for(int i=1;i<=n;i++)s[i]=s[i+1];
	for(int i=1;i<=n;i++)s2[i]=s2[i+1];
	for(int i=1;i<n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(sol(mid,i)<=m)r=mid-1;
			else l=mid+1;
		}
		if(i-l+1>ans){
		//	cout<<l<<' '<<i<<'\n';
			ans=i-l+1;
		}
	}
	cout<<ans+1;
}
