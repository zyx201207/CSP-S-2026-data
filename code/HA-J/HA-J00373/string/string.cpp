#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
typedef pair<int,int> PII;
const int N=2e5+5;
string p,w;
int L[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int ans=0,x,s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		string a;
		cin>>a;
		for(int j=1;j<=x;j++)
		{
			p+=a;
			s++;
		}
	}
	for(int i=1;i<s/2;i++)
	{
		if(p[i]!=p[s-i-1])
		{
			ans++;
		}
	}
	if(ans!=0) cout<<ans+1;
	else cout<<0; 
	return 0;
}
