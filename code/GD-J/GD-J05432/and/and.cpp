#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[2000005];

string ten_two(int x)
{
	string k="";
	char b[200005];
	int t=1;
	while(x>1)
	{
		if(x%2==1) b[t]='1';
		else b[t]='0';
		x/=2;
		t++;
	}
	b[t]='1';
	for(int i=t;i>=1;i--)
	{
		k+=b[i];
	}
	return k;
}

int mo(string s)
{
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1') ans++;
	}
	return ans;
}

bool cmp(int l,int z)
{
	if(mo(ten_two(l))==mo(ten_two(z))) return ten_two(l).size()>ten_two(z).size();
	return mo(ten_two(l))>mo(ten_two(z));
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int q=a[1];
	for(int i=2;i<=m;i++)
	{
		q=q&a[i];
	}
	cout<<q;
	return 0;
}
