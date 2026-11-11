// 2 hours have passed away?I didn't notice that.
#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[5000100];
long long del[5000100];
long long sum[5000100];
int ans;
bool check(int i,int j){
	if(sum[i - 1] - sum[j - 1] - (i - j) * (a[n] - a[i]) <= m) return true; // shen mi gong shi 
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		del[i] = a[n] - a[i];
	}
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + del[i];
	}
	for(int i = 1;i <= n;i++){
		int l = 1,r = i;
		while(r >= l){
			int mid = (l + r) >> 1;
			if(check(i,mid)){
				r = mid - 1;
				ans = max(ans,i - mid + 1);
			}
			else{
				l = mid + 1;
			}
		}
	}
	printf("%d",ans); 
	return 0;
}
