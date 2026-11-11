#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
long long val[1000100];
long long n,m;
void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		val[i] = a[i]-a[i-1];
	}
	int ans = 1,sum = 0;
	while(sum<=m){
		sum += ans*val[ans];
		ans++;
	}
	cout<<ans-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
