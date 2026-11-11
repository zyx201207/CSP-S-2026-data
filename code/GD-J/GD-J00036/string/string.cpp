#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+1;
int s[maxn]={},v[maxn]={};
int ans=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>v[i]>>ch;
		s[i]=ch-'0';
	}
	int i=1,j=n;
	while(i<=j)
	{
		if(s[i]==s[j])
		{
			if(v[i]==v[j]) 
			{
				i++;--j;continue;
			}
			else if(v[i]>v[j])
			{
				v[i]-=v[j];
				j--;continue;
			}
			else 
			{
				v[j]-=v[i];
				i++;continue;
			}
		}
		else
		{
			if(v[i]==v[j])
			{
				ans+=v[i];i++,--j;continue;
			}
			else if(v[i]>v[j])
			{
				ans+=v[j];v[i]-=v[j];j--;
			}
			else 
			{
				ans+=v[i];v[j]-=v[i];++i;
			}
		}
	}
	cout<<ans;
	//getchar();
	return 0;
} 
