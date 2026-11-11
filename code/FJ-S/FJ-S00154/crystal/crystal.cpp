#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
map<long long,int> mp; 
long long a[N];
long long m,mid,ans = 0,tans = 0;
bool check(int tmp) {
	long long sum = 0,num = 0;
	for(int i = tmp-1 ;i >= 1;i--) {
		if(a[i] == a[tmp]) {
			continue;
		} 
		if(sum+a[tmp]-a[i] <= m) {
			num ++;
			sum += a[tmp]-a[i];
		}else{
			break;
		}
	} 
	int le = mp[a[tmp]];
	if(num + le >= tans) {
		tans = max(tans,num + mp[a[tmp]]) ;
		return true;
	}else{
		return false;
	}
} 
int main() {
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	int tmp = 1,pos = 1;
	long long ch = 0;
	for(int i = 1 ;i <= n ;++i) {
		scanf("%lld",&a[i]);
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i = 1 ;i <= n ;++i) {
		if(a[i] - a[i-1] < ch) {
			int l = tmp-1,r = i;
			tans = 0;
			while(l+1<r) {
				int mid = l+((r-l)>>1);
				if(check(mid)){
					l = mid;
				}else{
					r = mid;
				}
			}
			ans = max(tans,ans);
			tmp = i;
			pos = 1;
		}
		if(pos != 1) {
			ch = a[i] - a[i-1];	
		}
		pos++;
	}
	tans = 0;
	int l = tmp-1,r = n+1;
	while(l+1<r) {
		int mid = l+((r-l)>>1);
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	ans = max(tans,ans);
	printf("%lld",ans);
	return 0;
}
