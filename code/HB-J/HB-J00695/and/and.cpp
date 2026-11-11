#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k,maxn=0;
int a[200005];
vector<int> book[35];

bool bookb[200005];
bool flag=false;

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(bookb,true,sizeof(bookb));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int temp=a[i];
		int c=1;
		while(temp)
		{
			if(temp%2)
				book[c].push_back(i);
			c*=2;
			temp/=2;
		}
	}
	for(int i=1;i<=30;i++)
	{
		if(book[i].size()<k+1) continue;
		cout<<i<<endl;
		maxn+=i;
	}
	
	cout<<maxn<<endl;
	return 0;
}
