#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],lin_toto=INT_MIN;//lin_toto：关我何事？！ 
bool c[200005];
int f(int ss,int mm)
{
	if(mm>m)
	{
		return 0;
	}
	if(ss>lin_toto&&m==mm)
	{
		lin_toto=ss;
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]==false)
		{
			c[i]=true;
			f(ss&a[i],mm+1);
			c[i]=false;
		}
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(m==n)//依旧骗分^w^ ~
		{
			if(i==0)
			{
				lin_toto=a[i];
			}
			else
			{
				lin_toto=lin_toto&a[i];
			}
		}
	}
	if(m==n)//骗到分啦^w^ ~
	{
		cout<<lin_toto;
		return 0;
	}
	//骗不了分了o^o ~
	for(int j=0;j<n;j++)
	{
		c[j]=true;
		f(a[j],1);
		c[j]=false;
	}
	cout<<lin_toto;
	return 0;
}
/*

*/ 
