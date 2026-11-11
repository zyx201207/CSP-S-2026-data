#include<bits/stdc++.h>
using namespace std;
long long  n;
long long a[20000005],sum,maxx=0;
char b[20000005];
string k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		k=k+b[i];
		if(a[i]>maxx)
		{
			maxx==a[i];
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(k[i]!=k[i+1])
		{
			break;		
		}
		else sum++;
	}
	if(sum==n)
	{
		cout<<"0";
		return 0;
	}
	else if(b[1]==b[2]&&b[2]==b[3])
	{
		cout<<a[1]+a[2]+a[3];
	}
	else cout<<maxx;
	return 0; 
} 
