#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int len[N];
int sum=0;
char str[N];
string last;
int ans=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>len[i]>>str[i];
		sum+=len[i];
		for(int j=1; j<=len[i]; j++)
		{
			last+=str[i];
		}
	}
	int f=1;
	for(int i=2; i<=n; i++)
	{
		if(str[i]==str[i-1])
		{
			f=1;
		}
		else
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		cout<<"0";
		return 0;
	}
	else
	{
		for(int i=0; i<=sum/2-1; i++)
		{
			if(last[i]==last[sum-1-i])
			{
				continue;
			}
			else
			{
				ans++;
			}
		}
	}
	cout<<ans;


	return 0;
}