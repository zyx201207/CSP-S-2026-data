#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct str
{
	long long a;
	char c;
};
long long n,ans;
str s[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	long long l=1,r=n,lyu=s[l].a,ryu=s[l].a;
	while(l<r)
	{
		if(s[l].c!=s[r].c)
			if(lyu<ryu) ans+=lyu,lyu=s[++l].a;
			else if(lyu==ryu) ans+=lyu,lyu=s[++l].a,ryu=s[--r].a;
			else ans+=ryu,ryu=s[--r].a;
		else
			if(lyu<ryu) lyu=s[++l].a;
			else if(lyu==ryu) lyu=s[++l].a,ryu=s[--r].a;
			else ryu=s[--r].a;
	}
	cout<<ans;
	return 0;
}
