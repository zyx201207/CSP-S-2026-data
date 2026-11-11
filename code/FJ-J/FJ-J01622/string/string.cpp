#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long len,ans;
pair<long long,char> a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		len+=a[i].first;
	}
	if(len%2==0)
	{
		len/=2;
		long long cnt=0,k=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i].first;
			if(cnt>=len)
			{
				k=i;
				break;
			}
		}
		if(cnt>len)
		{
			for(int i=n;i>k;i--)
			{
				a[i+1].first=a[i].first;
				a[i+1].second=a[i].second;
			}
			a[k+1].first=cnt-len;
			a[k+1].second=a[k].second;
			a[k].first=a[k].first-(cnt-len);
			n+=1;
		}
		for(int i=1,j=n;i<=k,j>k;i++,j--)
		{
			long long x1=a[i].first,x2=a[j].first;
			char c1=a[i].second,c2=a[j].second;
			if(x1==x2&&c1!=c2)
				ans+=x1;
			if(x1>x2)
			{
				ans+=x2;
				x1-=x2;
				while(1)
				{
					j--;
					if(a[j].first>=x1&&a[j].second!=c1)
					{
						a[j].first-=x1;
						ans+=x1;
						if(a[j].first>0)
							j++;
						break;
					}
					else if(a[j].second==c1)
					{
						j--;
						if(j<=k)
							break;
						continue;
					}
					if(a[j].first<x1)
					{
						ans+=a[j].first;
						x1-=a[j].first; 
					}
				}
			} 
			else if(x1<x2)
			{
				ans+=x1;
				x2-=x1;
				while(1)
				{
					i++;
					if(a[i].first>=x2&&a[i].second!=c2)
					{
						a[i].first-=x2;
						ans+=x2;
						break;
					}
					else if(a[i].second==c2)
					{
						i++;
						if(i>k)
							break;
						continue;
					}
					if(a[i].first<x2)
					{
						ans+=a[i].first;
						x2-=a[i].first; 
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(len%2==1)
	{
		len/=2;
		long long cnt=0,k=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i].first;
			if(cnt>=len)
			{
				k=i;
				break;	
			}
		}
		if(cnt==len)
		{
			for(int i=n;i>k;i--)
			{
				a[i+1].first=a[i].first;
				a[i+1].second=a[i].second;
			}
			n+=1;
			a[k+1].first=1;
			a[k+2].first-=1;
			k+=1;
		}
		if(cnt>len)
		{
			for(int i=n;i>k;i--)
			{
				a[i+1].first=a[i].first;
				a[i+1].second=a[i].second;
			}
			n+=1;
			a[k].first-=1;
			a[k+1].first=1;
			k+=1;
		}
		for(int i=1,j=n;i<k,j>k;i++,j--)
		{
			long long x1=a[i].first,x2=a[j].first;
			char c1=a[i].second,c2=a[j].second;
			if(x1==x2&&c1!=c2)
				ans+=x1;
			if(x1>x2)
			{
				ans+=x2;
				x1-=x2;
				while(1)
				{
					j--;
					if(a[j].first>=x1&&a[j].second!=c1)
					{
						a[j].first-=x1;
						ans+=x1;
						break;
					}
					else if(a[j].second==c1)
					{
						j--;
						if(j<=k)
							break;
						continue;
					}
					if(a[j].first<x1)
					{
						ans+=a[j].first;
						x1-=a[j].first; 
					}
				}
			} 
			else if(x1<x2)
			{
				ans+=x1;
				x2-=x1;
				while(1)
				{
					i++;
					if(a[i].first>=x2&&a[i].second!=c2)
					{
						a[i].first-=x2;
						ans+=x2;
						if(a[i].first>0)
							i--;
						break;
					}
					else if(a[1].second==c2)
					{
						i++;
						if(i>=k)
							break;
						continue;
					}
					if(a[i].first<x2)
					{
						ans+=a[i].first;
						x2-=a[i].first; 
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
