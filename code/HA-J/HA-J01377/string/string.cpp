#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int m;double s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].m >> a[i].s;
	}int sum=n,ans=0;
	for(int i=1;i <= n; i++){
		if(a[i].m >= a[sum].m and a[i].s != a[sum].s){
			a[i].m -= a[sum].m;
			ans+=a[sum].m;
			a[sum].s=a[i].s;
			sum--;
		}else{
			a[sum].m -= a[i].m;
			ans+=a[i].m;
			a[i].s=a[sum].s;
			sum--;
		}
	}
	cout << ans;
return 0;} 
