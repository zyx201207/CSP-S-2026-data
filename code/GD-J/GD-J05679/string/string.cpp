#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e8+5;
int a,b[N],n,m;
char c[N],s[N];
bool f()
{
	for(int i=0,j=n-1;i<n/2;i++,j--)
	{
		if(s[i]!=s[j])
		return 0;
	}
	return 1;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i]>>c[i];
		for(int j=0;j<b[i];j++)
		s[n+j]=c[i];
		n+=b[i];
	}
	while(!f())
	{
		for(int ii=0,jj=n-1;ii<n/2;ii++,jj--)
		{
			if(s[ii]!=s[jj])
			{
				s[jj]=s[ii];
				m++;
			}
		}
	}
	cout<<m;
	return 0;
}
