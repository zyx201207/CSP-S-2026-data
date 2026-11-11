#include<bits/stdc++.h>
using namespace std;
int n;
long long sum; 
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=1;
	string la;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		string a;
		cin>>a;
		if(a==la||i==1)
		{
			la=a;
		} 
		else
		{
			flag=0;
		}
		for(int j=cnt;j<=cnt+x-1;j++)
		{
			s+=a;
		}
		cnt+=x;
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}  
	long long ans=0;
	for(int i=0;i<cnt/2;i++)
	{
		
		if(s[i]!=s[cnt-i-2])
		{
			ans++;
		} 
	} 
	cout<<ans;
	return 0;
 }

