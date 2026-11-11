//GZ-J00071 张世铠 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll ans[300005];
bool vis[300005];
int n,m;
void solve(ll st){
	stack<ll> s;
	for(int i=st;i<=n;i++){
		if(vis[a[i]]==0){
			s.push(a[i]);
		}
		else{
			ll p;
			while(1){
				p=s.top();
				s.pop();
				vis[p]=0;
				if(p==a[i]){
					break;
				}
			}
			s.push(a[i]);
		}
		vis[a[i]]=1;
	}
	while(!s.empty()){
		ll p=s.top();
		s.pop();
		vis[p]=0;
		ans[p]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		solve(j);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
