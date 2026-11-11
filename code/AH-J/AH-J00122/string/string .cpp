#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt,ans;
char c[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		cnt+=a[i];
	}
	int k=cnt;
	if(k%2==1)
	{
		for(int i=0;i<=cnt/2;i++)
		{
			if(s[i]!=s[cnt-i-1])
			{
				ans++;
				
				}
		}
	}
	else
	{
		for(int i=0;i<=cnt/2;i++)
		{
			if(s[i]!=s[cnt-1-i]) ans++;
		}
	}
	cout<<ans;
}
	

                                              
