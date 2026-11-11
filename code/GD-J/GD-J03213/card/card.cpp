#include <bits/stdc++.h>
using namespace std;
const int N=500005;
struct card{
	long long a,i;
}c[N];
long long a[N],b[N],ans[N];
bool cmp(card a,card b){
	if (a.a!=b.a){
		return a.a<b.a;
	}else{
		return a.i<b.i;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		c[i].a=a[i];
		c[i].i=i;
	}
	sort(c+1,c+1+n,cmp);
	for (long long i=1;i<n;i++){
		if (c[i].a==c[i+1].a){
			b[c[i].i]=c[i+1].i;
		}
	}
	for (long long i=1;i<=n;i++){
		long long j=i;
		while (j<n){
			if (b[j]!=0){
				j=b[j];
			}else{
				ans[a[j]]+=1;
				j+=1;
			}
		}
		ans[a[n]]+=1;
	}
	for (long long i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}

