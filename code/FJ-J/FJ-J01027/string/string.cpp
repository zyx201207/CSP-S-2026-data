#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,bn,m=0,cn=0,ans=0,maxx=0,cx[30][200010];
string wx=" ";
map<char,int> mp;
struct node{
	int num;
	char ch;
};
node sum[200010];
struct ndoe{
	int l,r;
};
ndoe ax[200010];
int find(int cx)
{
	int l=1,r=n;
	while (l<r)
	{
		int mid=l+r+1>>1;
		if(ax[mid].l<=cx) l=mid;
		else r=mid-1;
	}
	return l;
}
int query(int l,int r,char ch)
{
	if(l>r) return 0;
	return cx[mp[ch]][r]-cx[mp[ch]][l-1];
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=26;++i)
	  mp[(char)('a'+i-1)]=i;
	for (int i=1;i<=n;++i)
	{
		cin>>sum[i].num>>sum[i].ch;
		maxx=max(maxx,sum[i].num);
		++cn;ax[i].l=cn;bn+=sum[i].num;
		cn+=sum[i].num-1;ax[i].r=cn;
	}
	if(maxx<=500)
	{
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=sum[i].num;++j)
			  wx+=sum[i].ch;
		}
		for (int i=1;i<=(int)(bn/2);++i)
		  if(wx[i]!=wx[bn-i+1]) ++ans;
		cout<<ans<<'\n';
		return 0;
	}
	for (int i=n;i>=1;--i)
	{
		for (int j=1;j<=26;++j)
		{
			cx[j][i]=cx[j][i-1];
			if(mp[sum[i].ch]!=j) cx[j][i]+=sum[i].num; 
		}
	}
	m=bn/2;
	int wn=find(m);
	for (int i=1;i<=wn;++i)
	{
		int l=bn-ax[i].r+1,r=bn-ax[i].l+1;
		if(i==wn) l=bn-m+1;
		int al=find(l),ar=find(r);
//		cout<<i<<' '<<l<<' '<<r<<' '<<al<<' '<<ar<<'\n';
		ans+=query(al+1,ar-1,sum[i].ch);
		if(sum[al].ch!=sum[i].ch) ans+=ax[al].r-l+1;
		if(sum[ar].ch!=sum[i].ch&&al!=ar) ans+=r-ax[ar].l+1;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
