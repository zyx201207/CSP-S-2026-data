#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll ans;
ll a[N];
ll n,m;
ll len,cnt;
queue<ll> qp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		len++;
		qp.push(a[i]);
		cnt=cnt+(len-1)*(a[i]-a[i-1]);
		while(cnt>m&&qp.size()!=0){
			ll u=qp.front();
			qp.pop();
			len--;
			cnt=cnt-(a[i]-u);
		}
		if(cnt>m){
			cnt=0;
			len=0;
			continue;
		}
		else{
			ans=max(ans,len);
		}
	}
	cout<<ans;
	return 0;
}
//fc crystal.out crystal4.ans
