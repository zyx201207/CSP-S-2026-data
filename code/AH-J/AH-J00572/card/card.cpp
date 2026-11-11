#include<bits/stdc++.h>
using namespace std;
long long n,m,flg=1;
long long a[500005],s[500005],f[500005];
stack<long long> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) 
	{
		if(a[i]<a[i-1]) 
		{
			flg=0;
			break;
		}
	}
	if(n<=500)
	{
		for(int k=1;k<=n;k++)
		{
			memset(f,0,sizeof(f));
			for(int i=k;i<=n;i++)
			{
				if(f[a[i]]==1)
				{
					while(1)
					{
						long long t=st.top();
						st.pop();
						f[t]--;
						if(t==a[i]) break;
					}
				}
				st.push(a[i]);
				f[a[i]]++;
			}
			for(int i=1;i<=m;i++) s[i]+=f[i];
		}
		for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	}
	else if(m==1)
	{
		cout<<n;
	}
	else if(m==2)
	{
		long long s=0,s2=0;
		for(int i=1;i<=n;i++) 
		{
			if(a[i]==1) s++;
			else s2++;
		}
		if(a[n]==1) 
		{
			cout<<n<<' '<<s2;
		}
		else
		{
			cout<<s<<' '<<n;
		}
	}
	else if(flg==1)	
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1]) cout<<i<<' ';
		}
	}
	return 0;
}
