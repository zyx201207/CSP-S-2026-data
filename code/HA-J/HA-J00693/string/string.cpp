#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

const int MAXN=800005;

int n;
int a[MAXN];
char c[MAXN][3];

map<ll,char> st[2];
set<pair<ll,char> > stt[2];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ll L=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%s",&a[i],c[i]);
		L+=a[i];
	}
	
	ll mid=L/2;
	ll len=0;
	for (int i=1;i<=n;i++)
	{
		len+=a[i];
		len=min(len,mid);
		st[0][len]=c[i][0];
		stt[0].insert({len,c[i][0]});
		if (len==mid) break;
	}
	
	len=0;
	for (int i=n;i>=1;i--)
	{
		len+=a[i];
		len=min(len,mid);
		st[1][len]=c[i][0];
		stt[1].insert({len,c[i][0]});
		if (len==mid) break;
	}
	
	for (map<ll,char>::iterator it=st[0].begin();it!=st[0].end();it++)
	{
		ll pos=(*it).first;
		if (st[1].find(pos)==st[1].end()) st[1][pos]=(*stt[1].upper_bound({pos,0})).second;
	}
	
	for (map<ll,char>::iterator it=st[1].begin();it!=st[1].end();it++)
	{
		ll pos=(*it).first;
		if (st[0].find(pos)==st[0].end()) st[0][pos]=(*stt[0].upper_bound({pos,0})).second;
	}
	
	ll ans=0;
	ll lst=0;
	for (map<ll,char>::iterator it=st[0].begin();it!=st[0].end();it++)
	{
		if ((*it).second!=st[1][(*it).first]) ans+=(*it).first-lst;
		lst=(*it).first;
	}
	
	printf("%lld",ans);
	
	return 0;
}
