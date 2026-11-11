#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200005;
ll a[N],ans;
int n,m;
bool cmp(ll i,ll j){
	return i>j;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	if(m==1){
		cout<<ans;
		return 0;
	}if(m==n){
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
