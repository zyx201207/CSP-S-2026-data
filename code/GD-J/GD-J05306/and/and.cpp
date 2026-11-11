#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,a[1000000];
string jinzhi(int a)
{
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	string n="",n1="";
	while(a!=0)
	{
		n+=char(a%2)-'0';
		a/=2; 
	}
	for(int i=0;i<=n1.size()-1;i++)
	{
		n[i]=n1.size()-i-1;
	}
	return n;
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;i++)
		{
			string n1=jinzhi(a[i]);
			string n2=jinzhi(a[j]);
	}

	
	
	
                   
	return 0;
}
