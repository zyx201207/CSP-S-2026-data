#include <bits/stdc++.h>
using namespace std;
int n;
string g;
int a[231452];
char c[231452];
void s1()
{
	int ans=0;
	int len=g.size()-1;
	for(int i=0;i<=len/2;i++)
	{
		if(g[i]!=g[len-i])
		{
			ans++;
		}
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)
		{
			g+=c[i];
		}
	}
	s1();
} 
