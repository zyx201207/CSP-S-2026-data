	#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n, m, a[N], b[N], c[N];
int q[N], r, ans[N];
bool ap[N];
int Read() {
	int res=0; char ch=getchar();
	while('0'<=ch && ch<='9')
		res=res*10+ch-'0', ch=getchar();
	return res;
}
void fun20() {
	for(int i=n; i>=1; i--)
		if(!ap[a[i]]) ans[a[i]]=i, ap[a[i]]=1;
	for(int i=1; i<=m; i++)
		printf("%d ", ans[i]);
}
void funsmall() {
	for(int i=1; i<=n; i++, r=0) {
		for(int j=i; j<=n; j++) if(ap[a[j]]) {
			while(r>0 && q[r]!=a[j]) ap[q[r]]=0, r--;
		} else ap[a[j]]=1, q[++r]=a[j];
		for(int j=1; j<=m; j++)
			ans[j]+=ap[j], ap[j]=0;
	}
	for(int i=1; i<=m; i++)
		printf("%d ", ans[i]);
}
void funB(int nn=0) {
	for(int i=1; i<=n; i++)
		if(a[i]!=a[i-1])
			b[++nn]=a[i], c[nn]=1;
		else c[nn]++;
	for(int i=1; i<=nn; i++, r=0) {
		for(int j=i; j<=nn; j++) if(ap[b[j]]) {
			while(r>0 && b[q[r]]!=b[j]) ap[b[q[r]]]=0, r--;
			b[r]=j;
		} else ap[b[j]]=1, q[++r]=j;
		for(int j=1; j<=r; j++)
			ans[b[q[j]]]+=c[q[j]], ap[b[q[j]]]=0;
	}
	for(int i=1; i<=m; i++)
		printf("%d ", ans[i]);
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n=Read(), m=Read();int fl=1, pce=0;
	for(int i=1; i<=n; i++) {
		a[i]=Read(), pce+=(a[i]!=a[i-1]);
		fl=(a[i]<a[i-1] ? 0 : fl);
	}
	if(fl) return fun20(), 0;
	else if(pce<=6000 && n>1e4) return funB(), 0;
	else return funsmall(), 0;
	return 0;
}
