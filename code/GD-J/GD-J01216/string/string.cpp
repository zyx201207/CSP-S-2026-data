#include<bits/stdc++.h>
using namespace std;
long long a[1000000001],n,m=0,t=0;
char c[1000001],b[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=m;j<m+a[i];j++)
		{
			b[j]=c[i];
		}
		m=m+a[i];
	}
	for(int i=0;i<=m/2;i++)
	{
		if(b[i]!=b[m-1-i])t++;
	}
	cout<<t;
	return 0;
} 
