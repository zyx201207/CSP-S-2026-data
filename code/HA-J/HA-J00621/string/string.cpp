#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans1=0;
char ans[100000000+10];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=cnt;j<cnt+a;j++)
		{
			ans[j]=c;
		}
		cnt=cnt+a;
	}
	cnt=cnt-1;
	for(int i=0;i<cnt/2;i++)
	{
		if(ans[i]!=ans[cnt-i])
		{
			ans1++;
			ans[cnt-i]=ans[i];
		}
	}
	cout<<ans1;
	return 0;
} 
