#include "bits/stdc++.h"
using namespace std;
int n,m,maxn;
long long a[200005],b[200005][50];
string s[200005];
inline long long mx (long long c,long long d){
	return c>d?c:d;
}
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf ("%d",&a[i]);
		while (a[i]){
			b[i][++b[i][0]]=a[i]%2ll;
			a[i]/=2ll;
		}
		maxn=mx(maxn,b[i][0]);
	}
	for (int i=1;i<=n;i++){
		for (int j=maxn;j>=1;j--){
			s[i]+=(b[i][j]+'0');
		}
	}
	sort (s+1,s+1+n);
	long long j=1,ans=0,k=0;
	while (s[n-m-k+1][k]=='0'){
		k++;
	}
	for (int i=maxn-1;i>=k;i--){
		if (s[n-m-k+1][i]=='1'){
			ans+=j;
		}
//		printf ("%d  ",ans);
		j=j*2ll;
	}
	printf ("%lld\n",ans);
	return 0;
}
