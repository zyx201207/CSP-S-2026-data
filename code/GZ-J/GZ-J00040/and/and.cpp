//GZ-J00040 贵阳市第二实验中学 岑钰欣 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct String
{
	long long a;
	string c={0},d={0};
};
bool cmp(String a,String b)
{
	return a.a<b.a;
}
bool cmp1(String a,String b)
{
	return a.d<b.d;
}
int main(int argc, char** argv)
{
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	int n,m;
	cin>>n>>m;
	String A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i].a;
		long long b=A[i].a;
		for(int j=0;b>0;b/=2)
		{
			A[i].c[j]=b%2;
			j++;
		}
		if(m==2&&i>=1)
		{
		A[i].d=A[i].c&A[i-1].c;	
		}

	}
	if(m==1)
	{
		sort(A,A+n,cmp);
		cout<<A[0].a;
	}		
	sort(A,A+n,cmp1);
	A[0].a=0;
	for(int j=0;j<A[0].c.size();j++)
		{
			A[0].a+=A[0].c[j]*2;
		}
	cout<<A[0].a;
	return 0;
}
