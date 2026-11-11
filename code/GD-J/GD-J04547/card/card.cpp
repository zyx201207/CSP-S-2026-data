#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 5e5+5;
ll ans[N],a[N];
bool vis[N];
ll n,m,idx;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=n;i>=1;i--){
		ans[a[i]]++;
		if(a[i]!=a[i-1]) break;
		
	}
	for(ll i=1;i<=m;i++) {
		cout<<ans[i]<<' ';
	}
}


//4 3
//1 2 1 3


//10 3
//3 1 2 1 3 2 3 1 2 1


