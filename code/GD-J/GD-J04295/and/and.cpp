#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2*1e5+10;
ll n,m,a[N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
//	for(ll i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	return 0;
}
