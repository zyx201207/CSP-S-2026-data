#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200010], ans;
long long er[31]={0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
void dfs(int x, int ned, long long now){
	if(ned==0){
		ans=max(ans, now);
		return ;
	}
	if(x>n){
		if(ned==0){
			ans=max(ans, now);
		}
		return ;
	}
	for(int i=x+1; i<=n-ned+1; i++){
		dfs(i, ned-1, now&a[i]);
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		ans=a[1];
		for(int i=2; i<=n; i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				ans=max(ans, a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n<=20){
		dfs(0, m, 1073741823);
		cout<<ans;
	}
	else{
		int f=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=30; j++){
				if(er[j]-1!=a[i]){
					f=1;
				}
			}
		}
		if(f==0){
			ans=a[n];
			for(int i=1; i<m; i++){
				ans&=a[n-i];
			}
			cout<<ans;
			return 0;
		}
		for(int j=1; j<=30; j++){
			if(n==er[j]){
				ans=a[n];
				for(int i=1; i<m; i++){
					ans&=a[n-i];
				}
				cout<<ans;
				return 0;
			}
		}
		ans=a[n];
		for(int i=1; i<m; i++){
			ans&=a[n-i];
		}
		cout<<ans;
	}
	return 0;
}
