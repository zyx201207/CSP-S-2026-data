#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0,num[200005],cnt=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>c[i];
		cnt+=num[i];
	} 
	ll sum=0,i=1,x=n;
	if(cnt%2==1)
	{
		
		for(i=1;i<=n;i++)
		{
			sum+=num[i];
			if(sum>(cnt/2)) break;
		}
		num[i]--;
		for(i=1;i<=(x/2);)
		{
			ll l=i,r=n;
			if(c[l]==c[r])
			{
				if(num[l]>num[r])
				{
					ll d=num[r];
					
					num[l]-=d;
					n--;
				}else if(num[l]<num[r])
				{
					ll d=num[l];
					
					num[r]-=d;
					i++;
				}else
				{
					i++;n--;
				}
			}else
			{
				if(num[l]==num[r])
				{
					ans+=num[l];
					n--;i++;
				}else if(num[l]>num[r])
				{
					ans+=num[r];
					num[l]-=num[r];
					n--;
					
				}else
				{
					ans+=num[l];
					num[r]-=num[l];
					i++;
				}
			}
		} 
	}else 
	{
	    for(i=1;i<=(x/2);)
		{
			ll l=i,r=n;
			if(c[l]==c[r])
			{
				if(num[l]>num[r])
				{
					ll d=num[r];
					
					num[l]-=d;
					n--;
				}else if(num[l]<num[r])
				{
					ll d=num[l];
					
					num[r]-=d;
					i++;
				}else
				{
					i++;n--;
				}
			}else
			{
				if(num[l]==num[r])
				{
					ans+=num[l];
					n--;i++;
				}else if(num[l]>num[r])
				{
					ans+=num[r];
					num[l]-=num[r];
					n--;
					
				}else
				{
					ans+=num[l];
					num[r]-=num[l];
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
