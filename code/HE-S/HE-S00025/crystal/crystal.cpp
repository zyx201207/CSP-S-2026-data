/*#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,a[500005],maxn=-1e18,sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum = 0;
		ans = 0;
		for(int j = 1;j <= n;j++){
			if(sum > m || a[j] > a[i]){
				break;
			}
			sum+=a[i]-a[j];
			ans++;
		}
		maxn = max(maxn,ans);
	}
	cout << maxn;
	return 0;
} 
*/
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,a[5000005],ans,last,sum,cnt=1;
bool check(long long x){
	int sum=0;
	for(int i = 1;i <= x;i++){
		if(sum > m){
			return false;
		}
		sum += a[x]-a[i];
	}
	return true;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	last =a[2]-a[1];
	for(int i = 1;i < n;i++){
		if(a[i+1]-a[i] == last){
			sum++;
		}
	}
	if(last == 0){
		cout << n;
		return 0;
	}
	if(sum == n-1){
		while(cnt <= n){
			sum = (a[cnt]-a[1]+a[cnt])*cnt/2; 
			if(sum > m){
				break;
			}
			cnt++;
		}
		cout << cnt;
		return 0;
	} 
	long long l=1,r=n,mid;
	while(l < r){
		mid = (l+r+1)/2;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid-1;
		}
		ans = max(ans,l);
	}
	cout << l;
	return 0;
}
