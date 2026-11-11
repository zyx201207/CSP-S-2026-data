#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005];
ll w;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	w=a[1];
	for(int i=2;i<=m;i++){
		w=w|a[i];
	}
	cout<<w;
	return 0;
}
