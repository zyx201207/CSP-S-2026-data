#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N=5e5+5;
ll ans=1,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin >> n >> m ;
	for(int i=1;i<=n;i++){
		cin >> a[i] ;
	}
	int k=a[2]-a[1];
	while(m-k>=0){
		m-=k;
		ans++;
		k+=a[2]-a[1];
	}
	cout << ans ;
}