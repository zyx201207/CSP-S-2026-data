#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[200005];
bool cmp(const ll &a, const ll &b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=m;i++){
		if(i==1){
			k=a[i];
		}else{
			k&=a[i];
		}
	}
	cout<<k;
	return 0;
}
