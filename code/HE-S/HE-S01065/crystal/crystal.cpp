#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+5;

int n; ll m;
ll arr[MAXN];
ll sum[MAXN];
int ans;

void solve();

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++){
		cin >> arr[i];
	}
	
	sort(arr+1,arr+1+n);
	
	solve();
	
	cout << ans << '\n';
	
	return 0;
}

void solve(){
	int L=1;
	for(int i=1 ; i<=n ; i++){
		sum[i]=sum[i-1]+1ll*(arr[i]-arr[i-1])*(i-L);
		while(L<i && sum[i]>m){
			sum[i]-=arr[i]-arr[L];
			L++;
		}
		ans=max(ans,i-L+1);
	}
	return ;
}
