#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,i,l=1,r=1,ans;
long long m,a[N],cz[N],cnt;
bool cmp(long long x,long long y){return x<y;}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(i=2;i<=n;i++) cz[i]=a[i]-a[i-1];
	for(l=1;l<=n;l++)
	{
		if(r<l) r=l;
		while(cnt+cz[r+1]*(r-l+1)<=m && r+1<=n)
		{
			cnt+=cz[r+1]*(r-l+1);
			r++;
		}
		ans=max(ans,r-l+1);
		cnt-=a[r]-a[l];
	}
	cout<<ans;
	return 0;
}
