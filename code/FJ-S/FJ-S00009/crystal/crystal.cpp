#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],dp[N],ans,aa;
void dfs(){
	for(ll i=n;i>=1;i--){
		aa=a[n]-a[i]+aa;
		if(aa>m) break;
	}
	if(aa>m){
		n--;
		aa=0;
		dfs();
	}else{
		return;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs();
	cout<<n<<endl;
	return 0;
}

