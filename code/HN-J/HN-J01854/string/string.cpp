#include<bits/stdc++.h>
using namespace std;
bool hui(string n,long long len)
{
	int s=0;
	for(long long i=1;i<=len;i++)
	{
		if(n[i]==n[len+1-i])
		{
			s++;
		}
	}
	if(s==len/2+1)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i;
	char c;
	long long m,le=0,sum=0;
	string l;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m>>c;
		l+=m*c;
		le+=m;
	}
	if(hui(l,le)==0)
	{
		cout<<0;
	}
	else
	{
		for(i=1;i<=le/2;i++)
		{
			if(l[i]!=l[le+1-i])
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
