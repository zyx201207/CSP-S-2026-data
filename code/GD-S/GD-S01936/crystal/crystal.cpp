#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,t=1,tot=2;
ll a[2005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<int(m+1)/2;
	return 0;
}
