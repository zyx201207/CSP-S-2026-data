#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],an,ans,q,b[500001],k,x[500001],mi;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%lld",&x[i]);
		mi=min(x[i],mi);
	}
	for(int i=1; i<=n; i++){
		a[x[i]+abs(mi)]++;
		if(a[x[i]+abs(mi)]==1){
			b[++k]=x[i]+abs(mi);
		}
	}
	sort(b+1,b+k+1);
	an=ans=a[b[1]];
	for(int i=2; i<=k; i++){
		m=q,an=a[b[i]];
		for(int j=i-1; j>=1; j--){
			if(((b[i]-b[j])*a[b[j]])>m){
				an=an+(m/(b[i]-b[j]));
				break;
			} 
			an+=a[b[j]];
			m=m-((b[i]-b[j])*a[b[j]]);
		}
		ans=max(ans,an);
	}
	printf("%lld",ans);
	return 0;
} 
