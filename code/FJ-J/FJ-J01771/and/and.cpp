#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x,ll y){
	return x>y;
}
ll a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1];
	return 0;
}
