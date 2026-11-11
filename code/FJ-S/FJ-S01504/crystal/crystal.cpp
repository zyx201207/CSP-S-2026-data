#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,num;
struct node{
	ll x,y;
}a[1000000];
bool cmp1(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i<=n;i++){
		cin>>a[i].x;
	}
	sort(a+1,a+n+1,cmp1);
	for(ll i = 1;i<n;i++){
		a[i].y=a[i+1].x-a[i].x; 
	}
	for(int i = 1;i<=n;i++){
		if(a[i].y*num<m){
			m-=num*a[i].x;
			num++;
		}
	}
	cout<<num;
	return 0;
}
