#include<cstdio>
#include<algorithm>
#define N 500005
using namespace std;

using ll=long long;
int n,ans;
ll m,a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1); ll cur=0;
	for(int i=1,j=1;i<=n;i++) {
		cur+=a[i];
		while(a[i]*(i-j+1)-cur>m) cur-=a[j],j++;
		ans=max(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;
}

/*
check if <vector> <cmath> is open

check long long

最终一定会修改成某个 a[i]
排序+枚举，优先修改 j<i 的 a[j] 较大的那些 
two-pointer
O(n log n) 

14:40
*/
