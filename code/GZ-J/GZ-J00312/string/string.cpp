#include<bits/stdc++.h>
using namespace std;
long long f[100000],n,cnt,ans,l,t,o[100000];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>f[i];
		cnt+=f[i];
		cin>>s[i];
	}
	cnt/=2;
	for(int i=0;i<=n/2-1;i++)
	{
		if(s[i]==s[n-1-t])
		{
			if(f[i]<f[n-1-t])
			{
				f[n-1-t]-=f[i];
			}
			else if(f[i]>f[n-1-t])
			{
				f[i]-=f[n-1-t];
				t++;
				o[i]=1;
				i--;
			}
			else if(f[i]==f[n-1-t])
			{	
				t++;
			}
		}
		else if(ans+f[i]<=cnt||o[i])
		{
			if(f[i]<f[n-1-t])
			{
				l+=f[i];
				f[n-1-t]-=f[i];
			}
			else if(f[i]>f[n-1-t])
			{
				l+=f[n-1-t];
				f[i]-=f[n-1-t];
				t++;
				o[i]=1;
				i--;
			}
			else if(f[i]==f[n-1-t])
			{
				l+=f[i];
				t++;
			}
		}
		else
		{
			long long a,b;
			a=f[i]+ans-cnt;
			b=f[i]-a;
			l+=abs(b-a);
		}
		
	}
	cout<<l;
	return 0;
}
