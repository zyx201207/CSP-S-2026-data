#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500010],d[500010],f[500010],cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	LL n,m,r;
	cin>>n>>m;
	r=n;
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=n;i>=1;i--){
		if(f[a[i]]!=0){
			r=f[a[i]];
			d[i]-=1;
			d[r]+=1; 
		}
		f[a[i]]=i;
		d[i]+=1;
		d[n+1]-=1; 
	}
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		cnt[a[i]]+=d[i];
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	return 0;
}
