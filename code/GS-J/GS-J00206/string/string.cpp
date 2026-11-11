#include <bits/stdc++.h>

using namespace std;

long long n,a,i,ans,m;
char c;
char s[1000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a>>c;
		m+=a;
		while(a--)
		{
			s[i]=c;
			i++;
		}
	}
	long long j=m-1;
	if(m%2==0)
	{
		m/=2;
	}
	else  
	{
		m=m/2+1;
	}
	for(int k=0;k<m;k++)
	{
		if(s[k]!=s[j])
		{
			ans++;
		}
		j--;
	}
	cout<<ans<<endl;
	return 0;
}
