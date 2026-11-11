#include<bits/stdc++.h>
using namespace std;
int n,v1,sum=0;
char v2;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v1>>v2;
		for(int j=1;j<=v1;j++)
		{
			a[i+j]=v2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[n-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
