#include <bits/stdc++.h>
using namespace std;
int n, j, ans;
long long m, a[500002], cnt;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	j=1;	
	for(int i = 2; i <= n; i++){
		cnt+=(a[i]-a[i-1])*(i-j);
		while(cnt>m){
			cnt-=a[i]-a[j++];
		}
		ans=max(ans, i-j+1);
	}
	cout<<ans<<endl;
	return 0;
}