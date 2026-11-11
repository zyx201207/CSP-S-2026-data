#include <iostream>
#include <iomanip>
#include <algorithm>
#define mmx 200001
#define int long long
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int zeroandone='0'+'1';
string tbin,itr;
struct node{int a;string bin;} lst[mmx];
string substr(string x,int l,int r)
{
	string rt;
	fo (i,l,r) rt+=x[i];
	return rt;
}
bool cmp(string p,string q)
{
	if (p=="")
		return 1;
	if (p[0]+q[0]==zeroandone)
		return p[0]=='1';
	else
		return cmp(substr(p,1,p.size()-1),substr(q,1,q.size()-1));
}
signed main()
{
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,t,ans=0;
	char chr;
	cin>>n>>m;
	fo (i,1,n) cin>>lst[i].a;
	fo (i,1,n)
	{
		tbin="0000000000000000000000000000000";
		x=lst[i].a;
		t=31;
		while (x)
		{
			chr=(x%2+'0');
			tbin[--t]=chr;
			x/=2;
		}
		lst[i].bin=tbin;
	}
	sort(lst+1,lst+n+1,[](node p,node q){return cmp(p.bin,q.bin);});
	ans=lst[1].a;
	fo (i,2,m) ans&=lst[i].a;
	cout<<ans;
	return 0;
}
