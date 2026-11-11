#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ans[200100],b[200100],c[200100],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (long long i=1; i<=n; i++) cin >> a[i];
	for (long long i=1; i<=n; i++){
		t=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for (long long j=i; j<=n; j++){
			if (c[a[j]]!=0){
				for (long long k=c[a[j]]+1; k<=t; k++) c[b[k]]=0;
				t=c[a[j]];
			}
			else{
				b[++t]=a[j];
				c[a[j]]=++t;
			}
		}
		for (long long j=1; j<=t; j++) ans[b[j]]++;
	}
	for (long long i=1; i<=m; i++) cout << ans[i] << " ";
}
