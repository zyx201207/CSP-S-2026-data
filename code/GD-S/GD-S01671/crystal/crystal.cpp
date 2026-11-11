#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
using ll = long long;
ll a[N];
int n;
ll m;
int dp[N];
ll pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1] + a[i];
	}
	dp[1] = 1;
	int maxx = 0;
	int last = 1;
	for(int i=2;i<=n;i++){
		if((i-last) * a[i] - (pre[i-1] - pre[last-1]) <= m){
			maxx = max(maxx,i-last+1);
		}
		else{
			last++;
			i--;
		}
	}
	cout<<maxx;
	return 0;
} 
