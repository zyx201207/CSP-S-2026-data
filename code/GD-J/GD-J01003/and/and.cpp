#include<bits/stdc++.h>
const int N=2e5+10;
using namespace std;
int n,m;
long long a[N],b[55],ans,d[N][45],vis[N];
string fun(long long x)
{
	string a1="",a2="";
	while(x>0)
	{
		a1+=char((x%2)+'0');
		x/=2;
	}
	for(int i=a1.size()-1;i>=0;i--) a2+=a1[i];
	return a2;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		string c=fun(a[i]);
		for(int j=c.size()-1;j>=0;j--)
		{
			if(c[j]=='0') continue;
			b[c.size()-1-j]++;
			d[i][c.size()-1-j]=1;
		}
	}
	for(int i=31;i>=0;i--)
	{
		ans*=2;	
		for(int j=1;j<=n;j++)
		{
			if(vis[j]&&d[j][i]) b[i]--;
		}
		if(b[i]<m) continue;
		ans++;
		for(int j=1;j<=n;j++)
		{
			if(!d[j][i]) vis[j]=1;	
		}
	}
	cout<<ans;
	return 0;
}
