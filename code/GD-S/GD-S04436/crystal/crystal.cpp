#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[5*100000+5],ans,cnt;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=m;i++){
		if(m>i){
			m-=i;
			ans++;
		}
	}
	cout<<ans+1;
	return 0;
} 
