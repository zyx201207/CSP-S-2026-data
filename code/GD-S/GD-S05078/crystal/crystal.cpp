#include "bits/stdc++.h"
#define ll long long
#define By_mumu return 0
using namespace std;
ll n,m,a[500010],c[500010],ans;

void bfs(ll deep){
	if(deep==m+1){
		ll li=0;
		for(ll i=2;i<=n;i++){
			li=1;
			while(a[i]==a[i-1])
			{
				li++;
				i++;
			}
			ans = max(li,ans);
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		a[i]++;
		bfs(deep+1);
		a[i]--;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool temp=1;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i){
			temp=0;
		}
	}
	sort(a+1,a+n+1);
	//特性A
	if(temp){
		ans=1;
		for(ll i=1;m>=i&&ans<n;i++){
			ans++;
			m-=i;
		}
		cout << ans;
		return 0;
	}
	//特性B
	ll cha = a[2]-a[1];
	bool f=1;
	for(ll i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			f=0;
			break;
		}
	}
	if(f){
		ans=1;
		for(ll i=1;m>=i*cha&&ans<n;i++){
			ans++;
			m-=i*cha;
		}
		cout << ans;
		return 0;
	}
	//暴力
	for(ll i=2;i<=n;i++){
		c[i] = a[i]-a[i-1];
	}
	bfs(1);
	cout << ans;
	By_mumu;
} 
