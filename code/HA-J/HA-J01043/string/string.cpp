#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100010],zuidada1=-1,zuida1,zuida2,l=0,x,he=0;
	char c[100010],mm[100010];
	string s="";
	cin>>n;
	x=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		mm[i]=c[i];
		s=s+c[i];
		zuidada1=max(zuidada1,a[i]);
		he=he+a[i];
	}
	sort(mm+1,mm+n+1);
	if(mm[1]==mm[n])
	{
		cout<<0;
		return 0;
	}
	zuida1=he-zuidada1;
	cout<<zuida1;
	return 0;
}
