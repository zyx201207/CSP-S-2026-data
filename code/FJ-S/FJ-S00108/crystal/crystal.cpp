#include<stdio.h>
#include<algorithm>
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
ll pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	int j=0;
	for(int i=1;i<=n;i++){
		while((i-j)*a[i]-pre[i]+pre[j]>m)j++;
		if(i-j>ans)ans=i-j;
	}
	printf("%d",ans);
	return 0;
}