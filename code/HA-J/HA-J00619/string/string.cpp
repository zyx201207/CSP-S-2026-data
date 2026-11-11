#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,x[N],ans;
char y[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		if(i>=2&&x[i]!=x[i-1])
		{
			f=1;
		}
	}
	if(f==0)
	{
		for(int i=1;i<=n;i++)
		{
			s=s+y[i];
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=x[i];j++)
			{
				s=s+y[i];
			}
		}
	}
	int l=s.size();
	if(l%2==1)
	{
		int mi=l/2+1;
		for(int i=1;i<=l/2;i++)
		{
			if(s[mi-i-1]!=s[mi+i-1])
			{
				ans++;
			}
		}
	}
	else
	{
		int mi=l/2;
		for(int i=1;i<=mi;i++)
		{
			if(s[mi-i]!=s[mi+i-1])
			{
				ans++;
			}
		}
	}
	if(f==0)
	{
		cout<<ans*(x[1]);
	}
	else
	{
		cout<<ans;
	}
	
	
	return 0;
}
