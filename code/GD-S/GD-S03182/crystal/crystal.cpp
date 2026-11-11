#include<bits/stdc++.h>
using namespace std;
int a[7000000];
int t[70000]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin.tie(0);
	int qian = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i = n;i>=1;i--){
		long long maxn = a[i];
		long long cnt = 0;
		for(long long j = 1;j<=i;j++){
			cnt+=a[i]-a[j];
		}
		if(cnt<=m){
			cout<<i;
			return 0;
		}
	}


	return 0;
}

