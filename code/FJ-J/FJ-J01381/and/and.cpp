#include<iostream>
#include<bits/stdc++.h>
using namespace std;
# define r return
long long n,m,cnt=0;
long long num[100110];
string s1,s2;
long long an (long long l1,long long l2)
{
	long long num1=l1,num2=l2;
	long long cmp1=1,cmp2=1;
	long long step1=0;
	long long step2=0;
	while(cmp1<=num1)
	{
		cmp1*=2;
		step1++;
	}
	while(cmp2<=num2)
	{
		cmp2*=2;
		step2++;
	}
	if(step1==step2)
	{
		while(num1>0&&num2>0)
		{
				long long cmp=max(cmp1,cmp2);
				if(num1/cmp==num2/cmp)
					cnt+=cmp;
				num1-=cmp;
				num2-=cmp;
				cmp/=2;
		}
	}
	else if(step1>step2)
	{
		long long cmp3=min(cmp1,cmp2);
		for(int i=0;i<step1-step2;i++)
			s2[i]='0';
		for(int i=step1-step2;i<step2;i++)
		{
			if(num2/cmp2==1)
				s2[i]==1;
			else
				s2[i]==0;
			num2-=cmp2;
			cmp2/=2;
		}
		for(int i=0;i<step1;i++)
		{
			if(num1/cmp1==1)
				s1[i]==1;
			else
				s1[i]==0;
			num1-=cmp1;
			cmp1/=2;
		}
		for(int i=0;i<step1;i++)
		{
			if(s1[i]==s2[i])
				cnt+=cmp3;
			cmp3/=2;
		}
	}
	else if(step2>step1)
	{
		long long cmp4=min(cmp1,cmp2);
		for(int i=0;i<step2-step1;i++)
			s1[i]='0';
		for(int i=step2-step1;i<step1;i++)
		{
			if(num1/cmp1==1)
				s1[i]==1;
			else
				s1[i]==0;
			num1-=cmp1;
			cmp1/=2;
		}
		for(int i=0;i<step2;i++)
		{
			if(num2/cmp2==1)
				s2[i]==1;
			else
				s2[i]==0;
			num2-=cmp2;
			cmp2/=2;
		}
		for(int i=0;i<step2;i++)
		{
			if(s1[i]==s2[i])
				cnt+=cmp4;
			cmp1/=2;
		}
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>num[n];
	if(m==2) 
	{
		long long maxk=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				maxk=max(maxk,an(num[i],num[i+1]));
		}
		cout<<maxk;
		return 0;
	}
	else if(m==1)
	{
		long long max_num=0;
		for(int i=1;i<=n;i++)
			max_num=max(n,max_num);
		cout<<max_num;
		return 0;
	}
	return 0;
}

