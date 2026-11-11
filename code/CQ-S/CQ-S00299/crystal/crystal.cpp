#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
int n,mid;
ll m,a[MAXN],b[MAXN],res,mn=INF;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		res+=a[i];
	}
	res=(res+n-1)/n;
	for(int i=1;i<=n;i++){
		ll c=llabs(a[i]-res);
		mn=min(mn,c);
	}
	for(int i=1;i<=n;i++){
		if(llabs(a[i]-res)==mn){
			mid=i;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=llabs(a[i]-a[mid]);
	}
	sort(b+1,b+1+n);
//	for(int i=1;i<n;i++){
//		printf("%lld ",b[i]);
//	}
//	printf("\n");
	int ans=0;
	ll sum=0;
	while(sum<=m){
		ans++;
		sum+=b[ans];
//		printf("%d^%lld\n",ans,sum);
	}
	if(sum>m){
		ans--;
	}
	printf("%d",ans);
}
/*
5 8
-3 -1 2 2 7
*/
