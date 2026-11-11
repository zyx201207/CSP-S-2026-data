#include<bits/stdc++.h>
using namespace std;
int l;
long long cnt=0;
char fa2[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	while(l--)
	{
		int x;
		cin>>x;
		char u;
		cin>>u;
		for(int i=1;i<=x;i++)
		{
			fa2[i+cnt]=u;
		}
		cnt+=x;
	}
	long long ans=0;
	for(int i=1;i<=cnt/2;i++)
	{	
	    if(fa2[i]!=fa2[cnt-i+1])ans++;
	}
	cout<<ans;
	return 0;
}