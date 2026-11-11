#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,a[100001],length=0,sum=0;
	char c[100001];
	string b="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			b=b+c[i];
			length++;
		}
	}
	for(long long i=0;i<=(length+1)/2-1;i++)
	{
		if(b[i]!=b[length-i-1])sum++;
	}
	cout<<sum;
	
	
}