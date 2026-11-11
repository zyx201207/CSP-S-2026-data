#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=2e5+5;
struct node{
	ll num,val;
}bi[N];
ll n,m;
ll a[N];
bool cmp(node A,node B)
{
	return A.val>B.val;
}
ll getvalue(ll x)
{
	ll res=1,ans=0;
	while(x!=0)
	{
		if(x&1)
		{
			ans+=res;
		}
		res*=2;
		x=x>>1;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bi[i].num=i;
	}
	for(int i=1;i<=n;i++)
	{
		bi[i].val=getvalue(a[i]);
	}
//	cout<<"AAA"<<endl;
	sort(bi+1,bi+1+n,cmp);
	int cnt=a[bi[1].num];
	for(int i=2;i<=m;i++)
	{
		cnt&=a[bi[i].num];
	}
	cout<<cnt;
	return 0;
}//I can do it.
