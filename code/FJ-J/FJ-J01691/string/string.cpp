#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
long long n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string x="";
	for(int i=1;i<=n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			x+=c;
		}
	}
	bool bo=true;
	int k=0;
	for(int i=x.size()-1;i>=0;i--)
	{
		if(x[k]!=x[i])
		{
			bo=false;
			break;
		}
		k++;
	}
	
	if(bo==true) cout<<0;
	return 0;
} 
