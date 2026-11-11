#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],sum=0;
char k;
string s;
long long l1;
string fun(int a,char k)
{
	for(int j=1;j<=a;j++)
	{
		s+=k;
	}
	l1=(s.size()/2-1);
	return s;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>k;
		s=fun(a[i],k);
	}
	for(long long p=0;p<=l1;p++)
	{
		if(s[p]!=s[s.size()-p-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0; 
}// 3 2 a 2 b 1 c
