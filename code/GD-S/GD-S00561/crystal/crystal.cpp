#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];
bool cmp(long long a,long long b){
	return a<b;
}
void solve1(){
	sort(a+1,a+1+n,cmp);
	int ans = 1;
	long long ans1 = 0;
	bool ok = 0;
	for(int i = 2;i <= n;i++){
		b[i] = (a[i]-a[i-1])*(i-1);
		if(m >= b[i])
		{
			m-=b[i];
			ans++;
		}
		else{
			cout << ans;
			ok = 1;
			break;
		}
	}
	if(ok == 0)cout << n;
}
void solve2(){
	sort(a+1,a+1+n,cmp);
	long long ans = a[2]-a[1];
	for(int i = 2;i <= n;i++){
		int j = i;
		if(m < 1ll*(j*(j-1)/2)*ans){
			cout << i-1;
			break;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 5000)solve1();
	else solve2();
	return 0;
} 
