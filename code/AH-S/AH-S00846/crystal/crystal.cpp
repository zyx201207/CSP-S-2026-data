#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],s[500005];
bool check(int x){
	for(int i = x;i <= n;i++){
		if(a[i] * (long long)x - (s[i] - s[i - x]) <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	int l = 1,r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) if(r == l + 1) break; else l = mid;
		else r = mid - 1;
	}
	cout<<l;
	return 0;
}
