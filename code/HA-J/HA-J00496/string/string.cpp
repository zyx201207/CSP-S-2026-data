#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int m[MAXN];
char b[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool flag=true;
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i]>>b[i];
		ans+=m[i];
		
	}
	char c=b[1];
	for(int i=2;i<=n;i++)
	{
		if(b[i]!=c)
		{
			flag=false;
		}
	}
	if(flag)
	{
		cout<<0;
		return 0;
	} 
	if(m[1]==m[n])
	{
		cout<<0;
	}
	cout<<(ans-m[n])*2;
	
	return 0;
}
