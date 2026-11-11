#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct node{
	ll s;
	ll g;
};
node a[200010];
ll number1(ll o){
	ll p=0;
	while(o!=0){
		p+=o%2;
		o/=2;
	}
	return p;
}
bool cmp(node x,node y){
	return x.g<y.g;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		a[i].g=number1(a[i].s);
	}
	sort(a+1,a+n+1,cmp);
	ll an=a[n-m+1].s;
	for(int i=n-m+2;i<=n;i++){
		an=an&a[i].s;
	}
	cout<<an;
	return 0;
}
/*
5 3
31 3 1 15 7


4 2
3 15 12 12
*/