//GZ-J00426 ∫Î“„÷–—ß –Ï∫Î”Ó 

#include<bits/stdc++.h>
using namespace std;

string s;
long long n=0,sum=0,qq=0;
const long long N=1e8+1;
long long a[N];
char b[N];


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(long long j=0;j<a[i];j++)
		{
			s = s+b[i];
		}
		qq+=a[i];
	}
	if(qq%2!=0)
	{
		long long w=(qq-1)/2;
		long long o=(qq+1)/2;
		for(long long i=0;i<=w;i++)
		{
			if(s[o-i-1]!=s[o+i-1])
			{
				sum++;
			}
		}	
	}
	else
	{
		long long ss=qq/2;
		if(s[ss]!=s[ss+1]) sum++;
		for(long long i=1;i<=ss;i++)
		{
			if(s[ss-i]!=s[ss+i+1])
			{
				sum++;
			}
		}
	}
	cout<<sum<<"\n";
	return 0;
}

