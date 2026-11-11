#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n,m) for(ll i=n;i<=m;i++)
#define disrep(i,n,m) for(ll i=n;i>=m;i--)
ll a[500010],n,m,ans,jcl;
//等差数列和ai=i这一情况 
ll N = 0x3f3f3f3f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	rep(i,1,n){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);//升序，优先看相邻的 
	jcl = abs(abs(a[n])-abs(a[n-1]));//等差数值 
	m/=jcl;
	cout<<((m+1)/2+1)<<"\n";
	
	
	return 0;
}
