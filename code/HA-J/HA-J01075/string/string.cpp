#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int M=1e9+5;
struct node
{
	int n;
	char c;
};
node nd[2*N];
char ch[M];
int cnt;
int s;
int c;
ll sum;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nd[i].n>>nd[i].c;
		sum+=nd[i].n;
	}
	s=nd[n].n;
	c=n;
	for(int i=1;i<=n/2;i++)
	{
		while(nd[i].n>s)
		{
			c--;
			s+=nd[c].n;
		}
		for(int j=n;j>=c;j--)
		{
			if(nd[i].c!=nd[j].c)
			{
				cnt+=nd[j].n;
			}
		}
	}
	cout<<cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
