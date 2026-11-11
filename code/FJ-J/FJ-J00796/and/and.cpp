#include<bits/stdc++.h>
using namespace std;
int n, m, maxn=0;
long long a[200005], cnt;
vector<int> b[35];
void f(int ps)
{
	long long numn=a[ps];
	int cnt=0;
	while(numn>0)
	{
		if(numn&1)
		{
			b[cnt].push_back(a[ps]);
			maxn=max(maxn, cnt);
		}
		numn/=2;
		cnt++;
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		f(i);
	}
//	cout<<maxn<<endl;
//	for(int i=0; i<=maxn; i++)
//	{
//		cout<<b[maxn].size()<<endl;
//	}
//	cout<<endl<<endl;;
	while(maxn>=0 && b[maxn].size()<m)
	{
		maxn--;
//		cout<<b[maxn].size()<<endl;
	}
//	cout<<maxn<<endl;
	cnt=b[maxn][0];
	for(int i=1; i<m; i++)
	{
//		cout<<b[maxn][i]<<" ";
		cnt&=b[maxn][i];
	}
	cout<<cnt<<endl;
	return 0;
}
//Trick||Treat!Trick||Treat!Trick||Treat!
