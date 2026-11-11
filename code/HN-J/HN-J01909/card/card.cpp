#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,j,ml[300001],fl[300001],s,summ;
ll nl[500001],fa[500001],ans[500001];
inline ll read() {
	ll nmb=0;char zf=getchar();while(zf<'0'||zf>'9')zf=getchar();
	while('0'<=zf&&zf<='9'){nmb=(nmb<<1)+(nmb<<3)+(zf^48);zf=getchar();}return nmb;
}
inline void write(ll nmb){if(nmb>9)write(nmb/10);putchar((nmb%10)^48);}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for (i=1;i<=n;++i) nl[i]=read();
	for (i=n;i>0;--i) {
		if (fl[nl[i]]==0) fa[i]=i;
		else fa[i]=fl[nl[i]];
		fl[nl[i]]=i;
	}
	for (i=1;i<=n;++i) {
		s+=ans[i];
		if (i!=fa[i]) {
			ans[i]=ans[i]-s-i;
			ans[fa[i]]=ans[fa[i]]+s+i;
			s=-i;
		}
	}
	for (i=1;i<=n;++i) {
		ans[i]+=ans[i-1];
		ml[nl[i]]=ml[nl[i]]+i+ans[i];
	}
	for (i=1;i<=m;++i) {
		write(ml[i]);
		putchar(' ');
	}
	return 0;
}
