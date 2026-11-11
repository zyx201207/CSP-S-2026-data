#include<bits/stdc++.h>
using namespace std;
long long a[1000000005];
char b[100];
long long zong;
string s;
long long ji;
string neil,m;
long long cou;
long long d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(long long i=1;i<=n;i++) zong+=a[i];
	for(long long i=1;i<=n;i++)//3 2 a 2 b 1 c
	{
		for(long long j=1;j<=a[i];j++)
		{
			ji++;
			s[ji]=b[i];
		}
	}
	if(zong%2==1)
	{
		for(long long i=(zong+1)/2;i>=1;i--)
		{
			d++;
			neil[d]=s[i];
		}
		//cout<<endl;
		for(long long i=(zong+1)/2;i<=zong;i++)//aaaaa
		{
			m[i-(zong+1)/2+1]=s[i];
		}
		//cout<<endl;
		for(long long i=1;i<=(zong+1)/2;i++)
		{
			if(neil[i]!=m[i])
			{
				cou++;
				//cout<<i<<' '<<neil[i]<<' '<<m[i]<<endl;
			}
		}
	}//6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
	else
	{
		for(long long i=zong/2;i>=1;i--)
		{
			d++;
			neil[d]=s[i];
			//cout<<neil[d];
		}
		for(long long i=(zong+1)/2;i<=zong;i++)//aabbc
		{
			m[i-(zong+1)/2+1]=s[i];
			//cout<<m[i-(zong+1)/2];
		}
		
		for(long long i=1;i<=zong/2;i++)
		{
			if(neil[i]!=m[i]) cou++; 
		}
	}
	cout<<cou;
	//for(long long i=1;i<=zong;i++) cout<<s[i];
	return 0;
} 
