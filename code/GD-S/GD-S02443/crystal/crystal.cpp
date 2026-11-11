#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N];
ll n,m;
void solve1(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll m1=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(m1<(a[i]-a[j]))break;
			m1-=(a[i]-a[j]);
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
void solve2(){
	if(m==0){
		cout<<0;
		return;
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		if(m<a[i])break;
		m-=a[i];
		ans++;
	}
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(n<=5000)solve1();
	else solve2();
	return 0;
} 
