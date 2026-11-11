#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,mx=0,mn=2e9,zl=1; 
ll dp[10005][2],a[100005];
void fen25(){
	if(m==1){
		cout << mx;
	}else if(m==n){
		ll ans=a[1];
		for(int i = 2;i <= n;i++){
			ans&=a[i];
		}
		cout <<ans;
	}else if(m==2){
		ll ans=0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
	}else{
		cout << mn;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		zl&=a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	fen25();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
