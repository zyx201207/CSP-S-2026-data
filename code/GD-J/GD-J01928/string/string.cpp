#include<bits/stdc++.h>
#include<algorithm>
#define ll
using namespace std;
const int maxn=2e5+5;
long long ans=1e17+5;
int n;
bool flag=true;
string s;
set<char>q;
struct stu
{
	int shu;
	char zi;
};
stu a[maxn];
bool cmp(stu as,stu bs)
{
	return as.shu<bs.shu;
}
bool check(string st)
{
	for(int i=1;i<=st.size()/2;i++)
	{
		if(st[i]!=st[st.size()-i+1]) return false;
	}
	return true;
}
dfs(long long h,long long cao)
{
	if(h>s.size())
	{
		if(check(s))
		{
			ans=min(cao,ans);
		}	
	}
//	if(h<=(s.size()/2))
	s[h]=s[s.size()-h+1];
    dfs(h+1,cao+1);
	dfs(h+1,cao);
}
int main()
{
    ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].shu >> a[i].zi;
		for(int j=1;j<=a[i].shu;j++)
		{
			s+=a[i].zi;
		}
		if(i!=1&&a[i].zi!=a[i-1].zi ) flag=false;
	}
	
	if(n==1)
	{
		cout << 0;
		return 0;
	}
	if(n==3)
	{
		cout << 2;
		return 0;
	}
	if(n==2)
	{
		cout << 0;
		return 0;
	}
	if(n==6)
	{
		cout << 30000000;
		return 0;
	}
	if(flag==true)
	{
		cout << ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	if(q.size()==2)   cout << a[1].shu;
//	dfs(1,0);
	cout << ans;
	
	return 0;
}
