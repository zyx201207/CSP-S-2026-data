#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0, hlf, ans=0;
struct st
{
	int a;
	char c;
}str[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>str[i].a>>str[i].c;
		cnt+=str[i].a;
	}
	int p1=1, p2=n, qs1=str[1].a, qs2=str[n].a;
	while(p1<p2)
	{
		if(qs1>qs2)
		{
			if(str[p1].c!=str[p2].c)
			{
				ans+=qs2;
			}
			qs1-=qs2;
			p2--;
			qs2=str[p2].a;
		}
		else
		{
			if(str[p1].c!=str[p2].c)
			{
				ans+=qs1;
			}
			qs2-=qs1;
			p1++;
			qs1=str[p1].a;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//Trick||Treat!Trick||Treat!Trick||Treat!
