#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const ll N=2e5+10,G=5e2+8,inf=0x3f3f3f3f3f3f3f3f;
struct node
{
	ll num;
	char c;
}a[N],b[N];
ll n;
string s;
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n;
	f(i,1,n)
	{
		cin>>a[i].num;
		cin>>a[i].c;
		b[i].num=a[i].num;
		b[i].c=a[i].c;
//		f(j,1,a[i].num) s=s+a[i].c;
	}
	for(int i=1,j=n;i<=j;)
	{
		if(i==j) break;
		if(a[i].c==a[j].c)
		{
			if(a[i].num==a[j].num) i++,j--;
			else if(a[i].num>a[j].num)
			{
				a[i].num-=a[j].num;
				j--;
			}
			else if(a[i].num<a[j].num)
			{
				a[j].num-=a[i].num;
				i++;
			}
		}
		if(a[i].c!=a[j].c)
		{
			if(a[i].num==a[j].num)
			{
				ans+=a[i].num;
				i++,j--;
			}
			else if(a[i].num>a[j].num)
			{
				a[i].num-=a[j].num;
				ans+=a[j].num;
				j--;
			}
			else if(a[i].num<a[j].num)
			{
				a[j].num-=a[i].num;
				ans+=a[i].num;
				i++;
			}
		}
	}
	cout<<ans;
//	ll len=s.size();
//	s='.'+s;
//	for(int i=1,j=len;i<=j;i++,j--)
//	{
//		if(i==j) break;
//		if(s[i]!=s[j]) ans++;
//	}
//	cout<<ans;
	return 0;
}













































