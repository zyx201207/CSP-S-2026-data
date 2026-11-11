#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],s;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	s=a[1];
	for(int i=1;i<=m;i++){
		s&=a[i];
	}
	cout<<s;
	return 0;
}
