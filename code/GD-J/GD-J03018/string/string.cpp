#include<bits/stdc++.h> 
using namespace std;
const int MAXN=2e5+5;
char str[MAXN];
int n;
long long cnt=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		long long a;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			str[cnt]=c;
			cnt++;
		}
	}
	for(int i=0;i<=cnt/2;i++)
	{
		if(str[i]!=str[cnt-i-1]) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
