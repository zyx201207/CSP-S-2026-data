#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		m-=i*(abs(a[i+1]-a[i]));
		if(m<0){
			cout<<i;
			break;
		}
	}
	return 0;
}
