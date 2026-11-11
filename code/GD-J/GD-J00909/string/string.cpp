#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],k,s,ans,da,z,sum,p;
char b[200005];
string d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	if(s%2==1)z=s/2+1;
	else z=s/2;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
		if(ans>=z)
		{
			k=i;
			break;
		}
	}
	if(s%2==1)
	{
		ans=0;
		for(int i=1;i<=k-1;i++)
		sum+=a[i];
		a[k]=z-1-sum;
		p=z-1-a[k];
		if(p!=0)
		{
			for(int i=n+1;i>=k+2;i--)
			{
				a[i]=a[i-1];
				b[i]=b[i-1];
			}
			a[k+1]=p,b[k+1]=b[k];
		}
		int l=1,r=n+1;
		while(l<=r)
		{
			if(b[l]==b[r])
			{
				if(a[l]==a[r])l++,r--;
				else
				{
					if(a[l]<a[r])a[r]-=a[l],l++;
					else a[l]-=a[r],r--;
				}
			}
			else
			{
				if(a[l]==a[r])ans+=a[l],l++,r--;
				else
				{
					if(a[l]<a[r])ans+=a[l],a[r]-=a[l],l++;
					else ans+=a[r],a[l]-=a[r],r--;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else
	{
		ans=0;
		int l=1,r=n;
		while(l<=r)
		{
			if(b[l]==b[r])
			{
				if(a[l]==a[r])l++,r--;
				else
				{
					if(a[l]<a[r])a[r]-=a[l],l++;
					else a[l]-=a[r],r--;
				}
			}
			else
			{
				if(a[l]==a[r])ans+=a[l],l++,r--;
				else
				{
					if(a[l]<a[r])ans+=a[l],a[r]-=a[l],l++;
					else ans+=a[r],a[l]-=a[r],r--;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
