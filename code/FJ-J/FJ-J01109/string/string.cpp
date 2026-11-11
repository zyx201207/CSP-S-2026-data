#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
char c;
string s,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld %c",&a,&c);
		for(int j=0;j<a;j++)
		{
			s=s+c;
		}
	}
	for(int i=s.length()-1;i>=0;i--)
	{
		t+=s[i];
	}
	if(t==s)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		string qian,hou,dq,dh;
		
		if(s.length()%2==0)
		{
			qian=s.substr(0,s.length()/2);
			hou=s.substr(s.length()/2,s.length()/2);
		}
		else
		{
			qian=s.substr(0,s.length()/2);
			hou=s.substr(s.length()/2+1,s.length()/2);
		}
		for(int i=qian.length()-1;i>=0;i--)
		{
			dq+=qian[i];
			dh+=hou[i];
		}

		ll dqhou=0,dhqian=0;
		for(int i=0;i<qian.length();i++)
		{
			if(dq[i]!=hou[i])
			{
				dqhou++;
			}
			if(dh[i]!=qian[i])
			{
				dhqian++;
			}
		}
		printf("%lld\n",min(dqhou,dhqian));
		return 0;
	}
	return 0;
}
