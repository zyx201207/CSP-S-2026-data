#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,s,i,j,maxn;
vector<bool> p[31];
bool bl[200001],l[31];
inline ll read() {
	ll nmb=0;char zf=getchar();while(zf<'0'||zf>'9')zf=getchar();
	while('0'<=zf&&zf<='9'){nmb=(nmb<<1)+(nmb<<3)+(zf^48);zf=getchar();}return nmb;
}
inline void write(ll nmb){if(nmb>9)write(nmb/10);putchar((nmb%10)^48);}
void t_t(ll nmb) {
	ll ii,snm=1;
	for (ii=1;ii<31;++ii) snm*=2;
	--ii;
	while (ii>0) {
		if (snm<=nmb) {
			p[ii].push_back(1);
			nmb-=snm;
		}
		else p[ii].push_back(0);
		snm/=2;
		--ii;
	} 
	p[0].push_back(nmb);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for (i=1;i<=n;++i) {
		j=read();
		t_t(j);
	}
	for (i=30;i>=0;--i) {
		s=0;
		for (j=0;j<n;++j) if (!bl[j]) s+=p[i][j];
		if (s<m) continue;
		l[i]=1;
		for (j=0;j<n;++j) if (!bl[j]&&!p[i][j]) bl[j]=1;
	}
	j=1;
	maxn+=l[0];
	for (i=1;i<31;++i) {
		j*=2;
		maxn+=l[i]*j;
	}
	write(maxn);
	return 0;
}
