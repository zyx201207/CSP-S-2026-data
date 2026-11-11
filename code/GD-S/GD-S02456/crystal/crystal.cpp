#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,max_x;
ll a[500005];

ll kkk(){
	ll x = 0,cnt = 1;
	for(ll i = 1;i < n;i++){
		if(a[i] == a[i + 1]){
			cnt++;
		}
		x = max(cnt,x);
	}
	cout<<x;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
	} 
	
	sort(a + 1,a + n + 1);
	

	
	ll i = 1,j = 1;
	while(m > 0){
		i = 1,j = 1;
		while(a[i] == a[j]){
			j++;
		}
		if((j - i) * (a[j] - a[i]) > m) break;
		m -= (j - i) * (a[j] - a[i]);
		for(ll t = i;t < j;t++){
			a[t] = a[j];
		}
	}
	
	kkk();
	
	return 0;
}
