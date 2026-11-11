#include <bits/stdc++.h>
using namespace std;
const int N=1e9+5;
int n,ans,cnt;
char a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num;
		char zimu;
		cin>>num>>zimu;
		while(num--)
		{
			cnt++;
			a[cnt]=zimu;
		}
	}
	for(int i=1;i<=cnt/2;i++)
	{
		if(a[i]!=a[cnt+1-i])
			ans++;
	}
	cout<<ans;
	return 0;
 } 
