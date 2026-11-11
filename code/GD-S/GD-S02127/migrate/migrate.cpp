#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long d,x[N],vf[N],vg[N];
int n,pre[N],nxt[N],f[N],g[N];
long long solve(int l,int r) {
	for(int i=l,j=l; i<=r; i++) {
		while(j<r&&x[j+1]-x[i]<=d) j++;
		nxt[i]=j;
	}
	for(int i=r,j=r; i>=l; i--) {
		while(j>l&&x[i]-x[j-1]<=d) j--;
		pre[i]=j;
	}
	for(int i=l; i<r; i++) f[nxt[i]]++;
	for(int i=r; i>l; i--) g[pre[i]]++;
	for(int i=l; i<=r; i++) {
		vf[i]=f[i];
		if(i>l&&nxt[pre[i]]==i) vf[i]+=vf[pre[i]];
	}
	for(int i=r; i>=l; i--) {
		vg[i]=g[i];
		if(i<r&&pre[nxt[i]]==i) vg[i]+=vg[nxt[i]];
	}
	long long ans=0;
	for(int i=l; i<r; i++) {
		long long valf=f[i+1],valg=g[i];
		if(nxt[i]==i+1) valf--;
		if(pre[i+1]==i) valg--;
		if(i>l&&nxt[pre[i]]==i+1) valf+=vf[pre[i]];
		if(i+1<r&&pre[nxt[i+1]]==i) valg+=vg[nxt[i+1]];
		ans+=valf*valg;
	}
	return ans;
}
void work() {
	cin>>n>>d;
	for(int i=1; i<=n; i++) f[i]=g[i]=0;
	for(int i=1; i<=n; i++) cin>>x[i];
	int lst=1;
	long long ans=0;
	for(int i=2; i<=n; i++) if(x[i]-x[i-1]>d) ans+=solve(lst,i-1),lst=i;
	ans+=solve(lst,n);
	cout<<ans<<"\n";
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int cid,T;
	cin>>cid>>T;
	while(T--) work();
	return 0;
}
//samples passed at 16:36
//AKed in 2h10min
//dududu
