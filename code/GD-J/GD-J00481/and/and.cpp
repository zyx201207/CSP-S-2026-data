#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
int n,m;
ll a[N];
priority_queue<ll>q;
ll ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=31;i>=0;i--){
		ll mb=(1LL<<i);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&mb)&&(a[j]&ans)==ans){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=mb;
		}
	}
	cout<<ans;
	return 0; 
}
