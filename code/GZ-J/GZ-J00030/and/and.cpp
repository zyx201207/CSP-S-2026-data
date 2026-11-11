//GZ-J00030 华东师范大学附属贵阳学校 张歆昀 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	ll n,m,ans;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(ll i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
