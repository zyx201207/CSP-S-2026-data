#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int sum1,sum2;
int s1[100005],s2[100005];

void chu(int n1)
{
	
	
	sum1=0;
	int s[10005]={0};
	while (true)
	{
		if(n1<1) break;
		s[sum2]=n1%2;
		n1=n1/2;
		sum1++;
		
	}
	int pp=0;
	for(int i=sum2-1;i>0;i--)
	{
		s1[pp]=s[i];
		pp++;
	}
}

void chu1(int n2)
{
	
	sum2=0;
	int s[10005]={0};
	while (true)
	{
		if(n2<1) break;
		s[sum2]=n2%2;
		n2=n2/2;
		sum2++;
		
	}
	int pp=0;
	for(int i=sum2-1;i>0;i--)
	{
		s2[pp]=s[i];
		pp++;
	}
	
}

void ad()
{
	if(sum1 > sum2)
	{
		for(int i=0;i<sum1;i++)
		{
			if(s1[i] == 1 && s2[i] == 1) 
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	long long m,n;
	cin>>n>>m;
	int k[100005];
	for(int i=0;i<n;i++) cin>>k[i];

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			chu1(k[i]);
			chu(k[j]);
			ad()
		}
	
	
}
