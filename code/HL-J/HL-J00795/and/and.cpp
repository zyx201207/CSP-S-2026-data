#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],ans;
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}else{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
	}
	cout<<ans;
}
#undef int
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--){
		solve();
//	}
	return 0;
}
/*
10101001010000100
01001010010100101
01001001010101010
00001000010000000

*/