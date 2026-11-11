#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll printnumber[105];
inline ll in()
{
	ll ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=getchar();
	while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
	return ans*f;
}
inline void out(ll x,char y)
{
	ll tot=0;
	if(x<0)x=-x,putchar('-');
	do
	{
		printnumber[++tot]=x%10;
		x/=10;
	}while(x);
	while(tot)putchar(printnumber[tot--]+'0');
	putchar(y);
	return ;
}
ll n,m;
vector<ll> cnt,tmp;
int main()
{
	freopen("and.in","r",stdin);
	freopen("add.out","w",stdout);
	n=in(),m=in();
	for(int i=1;i<=n;i++)cnt.push_back(in());
	ll ans=0;
	for(ll j=31;j>=0;j--)
	{
		ll lenc=cnt.size(),lent=0;
		for(int i=0;i<lenc;i++)if(cnt[i]&(1ll<<j))tmp.push_back(cnt[i]);
		lent=tmp.size();
//		cout<<j<<" "<<lent<<"\n";
//		for(int i=0;i<lent;i++)cout<<tmp[i]<<" ";
//		cout<<"\n";
		if(lent>=m)
		{
			ans+=(1ll<<j);
			cnt.clear();
			for(int i=0;i<lent;i++)cnt.push_back(tmp[i]);
		}
		tmp.clear();
	}
	out(ans,'\0');
	return 0;
}
//zdx bless me junior group AK
//lmr bless me junior group AK
//hzy bless me junior group AK

