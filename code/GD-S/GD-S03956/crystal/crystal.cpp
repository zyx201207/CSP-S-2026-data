#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+100;
int n;
ll m;
ll a[N];
int ans=1;
bool cmp(ll x,ll y){
	return x<y;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		ll ned=0;
		for(int j=i;j>=1;j--){
			ned+=a[i]-a[j];
			if(ned<=m) ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
}

