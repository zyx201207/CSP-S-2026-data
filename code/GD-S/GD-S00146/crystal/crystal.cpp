#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500009],s[500009];
//check if the greedy is correct
// I don't know why I found the solution too fast
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i = 1; i <= n; i ++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	int ans = 1;
	for(int i = 1; i <= n; i ++){
		s[i] = s[i - 1] + a[i];
		int l = 1,r = i + 1;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(s[i] - s[i - mid] + m >= a[i] * mid)
				l = mid;
			else
				r = mid;
		}
		ans = max(ans,l);
	}
	printf("%d\n",ans);
}
