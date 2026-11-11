//GZ-S00132 贵阳市第一中学 李啸峰 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],d[N],Ans;
bool check(int x,int i)
{
	if(d[x]-(i-x+1)*(a[n]-a[i])-d[i+1]<=m)
		return true;
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)
		d[i]=d[i+1]+a[n]-a[i];
	for(int i=n;i>=1;i--)
	{
		int l=1,r=i,pos=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i))
			{
				pos=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
	 	Ans=max(Ans,i-pos+1);
	} 
	cout<<Ans<<endl;
	return 0;
}
