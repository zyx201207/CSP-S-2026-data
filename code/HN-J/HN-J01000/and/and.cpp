#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,a[9178666],b[9178666],m;
int cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(int i=1;i<=m-1;i++){
		ans+=a[i]&a[i+1];
	}
	cout<<ans;
	return 0;
}
