#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,b;
ll a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1)cout<<n;
	return 0;
}
