#include<bits/stdc++.h>
using namespace std;
int n;
long long num=0;
char c,b;
int a;
vector<long long> ni;
vector<char> mi;
int nn=0;
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	cin>>num>>b;
	for(int i=2;i<=n;i++)
	{
		cin>>a>>c;
		if(b==c)
			num+=a;
		else
		{
			ni.push_back(num);
			mi.push_back(b);
			num=a;
			nn++;
			b=c;
		}
	}
	nn++;
	ni.push_back(num);
	mi.push_back(b);
	num=0;
	if(nn%2==0)
	{
		n=nn;
		for(int i=1;n>i;)
		{
			if(mi[i]!=mi[n])
			{
				if(ni[i]==ni[n])
				{
					num+=ni[i];
					n--;
					i++;
				}
				else
				if(ni[i]<ni[n])
				{
					num+=ni[i];
					ni[n]-=ni[i];
					i++; 
				}
				else
				if(ni[i]>ni[n])
				{
					num+=ni[n];
					ni[i]-=ni[n];
					n--;
				}
			}
		}
		cout<<num;
	}
	else
	{
		n=nn;
		for(int i=1;n>i;)
		{
			if(i==nn/2+1||n==nn/2+1)
			{
				num+=min(ni[i],ni[n]);
				continue;
			}
			if(mi[i]!=mi[n])
			{
				if(ni[i]==ni[n])
				{
					num+=ni[i];
					n--;
					i++;
				}
				else
				if(ni[i]<ni[n])
				{
					num+=ni[i];
					ni[n]-=ni[i];
					i++; 
				}
				else
				if(ni[i]>ni[n])
				{
					num+=ni[n];
					ni[i]-=ni[n];
					n--;
				}
			}
		}
		cout<<num;
	}
	return 0;
} 
// 1024 MiB
