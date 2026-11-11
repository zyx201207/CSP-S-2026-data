#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],t;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1,j=n;;)
	{
		if(i==j||i>j)break;
		if(a[i]<a[j])
		{
			if(s[i]!=s[j])t=t+a[i];
			a[j]=a[j]-a[i];
			i++;
			continue;
		}
		if(a[i]>a[j])
		{
			if(s[i]!=s[j])t=t+a[j];
			a[i]=a[i]-a[j];
			j--;
			continue;
		}
		if(a[i]==a[j])
		{
			if(s[i]!=s[j])t=t+a[i];
			i++,j--;
			continue;
		}
	}
	cout<<t;
	
	return 0;
}
