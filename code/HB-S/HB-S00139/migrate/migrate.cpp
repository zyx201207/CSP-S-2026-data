#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+10;
#define filename "migrate"
#define rep(i,a,b) for(int i=(a);i<=(ll)b;++i)
#define getc getchar_unlocked()
#define putc putchar_unlocked
ll re(){
	ll res=0;bool s=0;char c=getc;
	for(;!isdigit(c);c=getc) s|=c=='-';
	for(;isdigit(c);c=getc) res=(res<<3)+(res<<1)+(c-'0');
	return s?-res:res;
}
void wr(ll x){
	if(x<0) putc('-'),x=-x;
	if(x>9) wr(x/10);
	putc(x%10+'0');
}
ll c,t;
int main()
{
	//ios::sync_with_stdio(false);cin.tie(nullptr);
	#if 1
		freopen(filename".in","r",stdin);
		freopen(filename".out","w",stdout);
	#endif
	c=re(),t=re();
	while (t--)
	{
		ll n=re(),d=re();
		ll k=d*2-1;
		vector<ll> x(n+10,0);
		map<ll,bool> cnt;
		rep(i,1,n) x[i]=re(),cnt[x[i]]=1;
		ll num=0;
		rep(i,1,n)
		{
			if(cnt[x[i]+k])
				num++;
		}
		wr(num),putc('\n');
	}

	return 0;
}
