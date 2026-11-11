#include<bits/stdc++.h>
using namespace std;
struct str
{ 
	int shuliang;
	char zifu;
 } st[1000000];
// char s[10000000000]={ '0' };
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s; 
//	char s[10000000000]={ '0' };
	for(int i=1;i<=n;i++)
	{
		cin>>st[i].shuliang>>st[i].zifu;
	}
	long long tt=1,a6=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<st[i].shuliang;j++)
		{
			a6+=st[i].zifu;
			if(a6>2147483647)
			{
				cout<<3000000000;
				return 0;
			}
			s+=st[i].zifu;
			tt++;
		}
	}
	int ans=0;
	//cout<<s;
	for(int i=0;i<=n/2;i++)
	{
		if(s[i]!=s[n-1-i])
		{
		ans++;	
		}
	}
	cout<<ans;
	return 0;
 } 
