#include<bits/stdc++.h>
using namespace std;
long long n,v1[200003],sum=0;
char v2[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v1[i]>>v2[i];
	}
	for(int i=0;i<(n+1)/2;i++)
	{
		if(v2[i]!=v2[n-i-1])
		{
			sum=sum+v1[i];
		}
	}
	cout<<sum;
	return 0;
}
