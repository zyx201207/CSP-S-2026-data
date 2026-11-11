#include <bits/stdc++.h>
using namespace std;
char s[2000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;//3
	long long now=1;//1   3    5
	cin>>n;//3
	while(n--)
	{
		long long a;
		char c;
		cin>>a>>c;//2 a     2 b    1 c
		long long x=0;
		for(long long i=now;i<=now+a-1;i++)//1--2   3--4   5-5
		{
			s[i]=c;//s[1]=a s[2]=a  
			x=i;//    s[3]=b   s[4]=b   s[5]=c
		}
		now=x+1;//now=3  now=5  now=6
	}
	long long ans=0;//0
	long long l=now-1;//5
	if(l%2!=0)
	{
		long long mid=(l+1)/2;//3
		for(int i=1;i<mid;i++)//1   2
		{
			if(s[mid-i]!=s[mid+i])//s[2]!=s[4] a!=b   s[1]!=s[5]
			{
				ans++;//ans=1   ans=2
			}
		}
	}
	cout<<ans;
	return 0;
}
