#include <bits/stdc++.h>
using namespace std;
int n,maxns=0;
int cnt=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	int f=1;
	string a;
	long long b=1;
	for(int i=1;i<=n;i++)
	{
		long long s;
		char c;
		string k;
		cin>>s>>c;
		while(s>=10)
		{
			s/=10;
			if(f==1)
			{
				b*=10;
			}
		}
		f=0;
		for(int j=1;j<=s;j++)
		{
			k[j]=c;
			a[cnt++]=k[j];
		}
		
	}

	
	
	
	long long l=1,r=cnt-1,ans=0;
	while(l<r)
	{
		if(a[l]!=a[r])
		{
			ans++;
		}
		l+=1;
		r-=1;
	}
	cout<<ans*b;
	
	return 0;
}
