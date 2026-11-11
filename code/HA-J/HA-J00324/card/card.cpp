#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
stack<ll> desk;
map<ll,bool> M;
ll ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		while(!desk.empty())desk.pop();
		M.clear();
		for(ll j=i;j<=n;j++){
			if(M[a[j]]==false){
				M[a[j]]=true;
				desk.push(a[j]);
			}
			else {
				while(1){
					if(desk.top()==a[j] || desk.empty())break;
					M[desk.top()]=false;
					desk.pop();
				}
				if(!desk.empty())desk.pop();
				desk.push(a[j]);
				M[a[j]]=true;
			} 
		}
		for(ll i=1;i<=m;i++){
			if(M[i]==true)ans[i]++;
		}
		
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
//这道题只想出来一个栈加map的暴力模拟解法，最多过九个测试点 
