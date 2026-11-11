#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int cnt=0,ans=0;
	int n;
	cin>>n;
	string S[100001];
	for(int i=1;i<=n;i++)
	{
		long long a;
		string s;
		cin>>a>>s;
		for(int i=1;i<=a;i++)
		{
			cnt++;
			S[cnt]=s;
		}
	}
	if(cnt%2==0)
	{
		int cnt1=cnt/2;
		for(int i=1;i<=cnt1;i++)
		{
			if(S[cnt1+1-i]!=S[cnt1+i]) ans++;
		}
	}
	else 
	{
		int cnt1=(cnt+1)/2;
		for(int i=1;i<=cnt1;i++)
		{
			if(S[cnt1-i]!=S[cnt1+i]) ans++;
		}
	}
	cout<<ans;
	return 0;
	
}
