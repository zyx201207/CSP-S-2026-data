#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=5e5;
const long long maxm=1e18;
long long a[maxn];
long long b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	int A=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==i) ++A;
	}
	if(A==n){
		int x=1;
		while(x*(x-1)/2<=m) ++x;
		printf("%d",x-1);
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		int l=1,cost=0;
		for(int j=i+1;j<=n;j++){
			if(cost+b[j]*l>m) break;
			b[i]+=b[j];
			b[j]=0;
			cost+=b[j]*l;
			++l;
		}
		ans=max(ans,l);
		for(int j=1;j<=n;j++) b[j]=a[j]-a[j-1];
	}
	printf("%d",ans);
	return 0;
}
