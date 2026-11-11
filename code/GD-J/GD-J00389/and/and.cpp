#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e9+9;
using ll=long long;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
void solved(){
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ans=a[1];
	if(m==1){
		cout<<ans;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			ans=ans&&a[i];
		}
		cout<<ans;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	int t; cin>>t;
	solved();
	return 0;
} 
