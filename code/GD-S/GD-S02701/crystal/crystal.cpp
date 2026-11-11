#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
#define int long long
int n,a[N],m;
int en[N],ans = 1;
void solve1(){
	for(int i = 2;i <= n;i ++){
		int del = a[i]-a[i-1],sum = 0;
		for(int j = i-1;j >= 1;j--){
			en[j] += del;
			if(sum + en[j]<=m){
				ans = max(ans,i-j+1);
				sum += en[j];
			}
			else break;
		}
	}
	cout << ans;	
}
void solve2(){
	int l = 1,sum = 0;
	for(int i = 2;i <= n;i ++){
		int del = a[i]-a[i-1];
		sum += del*(i-l);
		while(sum > m){
			sum-=a[i]-a[l];
			l++;
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;	
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)cin >> a[i];
	sort(a+1,a+1+n);
	solve2();
	return 0;
} 
