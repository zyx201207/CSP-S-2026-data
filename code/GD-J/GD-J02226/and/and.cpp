#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
struct node{
	ll a,s;
}a[200010];
void f(int i,ll x){
	while(x){
		if(x%2)a[i].s++;
		x/=2;
	}
	
}
bool cmp(node x,node y){
	if(x.s==y.s)return x.a>y.a;
	return x.s >y.s;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		f(i,a[i].a);
	}
	sort(a+1,a+n+1,cmp);
	ll ans=a[1].a;
	for(int i=2;i<=m;i++){
		ans&=a[i].a;
	}
	cout<<ans;
	
	return 0;
}
