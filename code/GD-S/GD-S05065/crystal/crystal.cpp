#include <cstdio>
#include <algorithm>
#define ll long long
const int N = 5e5 + 5;
using namespace std;

int n; ll m;
ll a[N];

int ans;
ll pre[N];

int solve(const int& left,const int& right){
	int l,r,mid;
	int res = 0;
	l = left; r = right;
	while(l <= r){
		mid = l + ((r - l) >> 1);
		if(pre[right - 1] - pre[mid - 1] + m >= a[right] * (right - mid)){
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1,j;i <= n;i++){
		j = solve(1,i);
		ans = max(ans,i - j + 1);
	}
	printf("%d",ans);
	return 0;
}

