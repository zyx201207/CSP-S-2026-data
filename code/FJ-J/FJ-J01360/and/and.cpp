#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10; 
struct l{
	ll r,x;
}a[N];
ll n,m,cut;
ll gs(ll n){
	ll q=0;
	while (n!=0){
		if (n%2==1) q++;
		n/=2;
	}
	return q;
}
bool cmp(l a,l b){
	if (a.x==b.x) return a.r>b.r;
	return a.x>b.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i].r;
		a[i].x=gs(a[i].r);
	}
	sort (a+1,a+n+1,cmp);
	cut=a[1].r;
	for (int i=1;i<=m;i++){
		cut=(cut&a[i].r)
	}
	cout<<cut;
	return 0;
}
