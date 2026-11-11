#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans1=0x3f3f3f3f3f3f3f3f;
long long ans2=0x3f3f3f3f3f3f3f3f;
struct node{
	long long a;
	int c;
}s[200010];
bool cmp(node a,node b)
{
	return a.a>b.a;
}
bool kp(node a,node b)
{
	return a.c>b.c;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a;
	}
	for(int i=0;i<=n;i++)
	{
		long long k=s[i].a;
		int cnt=0; 
		while(k)
		{
			cnt++;
			k=k&(k-1);
			//cout<<cnt<<" ";
		}
		s[i].c=cnt;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=m;i++)
	{
		ans1&=s[i].a;
	}
	sort(s+1,s+1+n,kp);
	for(int i=1;i<=m;i++)
	{
		ans2&=s[i].a;
	}
	cout<<max(ans1,ans2)<<endl;
	cout<<s[1].a<<" "<<s[2].a;
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].c<<" "<<s[i].a<<endl;
	}
	return 0;
 } 
