#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[100005];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n%2!=0){
		cout<<a[n/2];
	}else if(n%2==0){
		cout<<a[n/2-1];
	}
	return 0;
}