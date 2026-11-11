#include<bits/stdc++.h>
using namespace std;
int ans=2147483647;
struct T
{
	int x,n1;
	string s;
}a[200006];
int n,m;
void zhuanerjinzhi(int c,int k)
{
	string s1;
	while(c)
	{
		s1+=(c%2)+'0';
		c>>=1;
	}
	int l=s1.size();
	for(int i=l-1;i>=0;i--)
	{
		a[k].s+=s1[i];
	}
}
bool cmp(T x,T y)
{
	return x.s>y.s;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		zhuanerjinzhi(a[i].x,i);
	}
	sort(a+1,a+n+1,cmp);
	int f=1;
	while(m--)
	{
		ans&=a[f].x;
		f++;
	}
	cout<<ans;
	return 0;
}
