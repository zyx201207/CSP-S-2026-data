#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,k,sum=0;
char c;
string a="";
int main(){
		freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>k>>c;
		for(long long i=1;i<=k;i++) 
			a+=c;
	}
	int L=a.size();
	for(long long i=1;i<=L/2;i++)
	{
		if(a[i-1]!=a[L-i])
		{
			sum++;
		}
	}
	cout<<sum;
	
	return 0;
}
