#include<bits/stdc++.h>
using namespace std;
long long lvis[200005],rvis[200007],n,a[200005],x,rsum,lsum,h[200005],g,ans,mi;
char b[200005],c,lc[200005],rc[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		h[i]=h[i-1]+a[i];
	}
	g=lower_bound(h+1,h+n+1,h[n]/2)-h;
	for(int i=1;i<=n;i++)
	{
		if(i!=g)
		{
			if(x==0)
			{
				if(b[i]==lc[lsum])
					lvis[lsum]+=a[i];
				else
				{
					lc[++lsum]=b[i];
					lvis[lsum]=a[i];
				}	
			} 
			else
			{
				if(b[i]==rc[rsum])
					rvis[rsum]+=a[i];
				else
				{
					rc[++rsum]=b[i];
					rvis[rsum]=a[i];
				}
			}
		}
		else
		{
			x=1;
			if(h[g]!=h[n]/2)
			{
				int t=h[n]/2-h[g-1];
				if(b[i]==lc[lsum])
					lvis[lsum]+=t;
				else
				{
					lc[++lsum]=b[i];
					lvis[lsum]=t;
				}
				t=a[i]-t;
				rvis[++rsum]=t;
				rc[rsum]=b[i];
			}
			else
			{
				if(b[i]==lc[lsum])
					lvis[lsum]+=a[i];
				else
				{
					lc[++lsum]=b[i];
					lvis[lsum]=a[i];
				}
			}
		}
	 }
	for(int i=1,j=min(lsum,rsum);i<=j;i++,j--)
	{
		if(lc[i]!=rc[j])
			ans+=min(lvis[i],rvis[j]);
		else
			ans+=abs(lvis[i]-rvis[j]);
	}
	cout<<ans;
	return 0;
} 
