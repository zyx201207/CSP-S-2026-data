#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll ans=0;
struct node{
	ll v;
	ll id;
}a[200005];
ll mid=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;char c;
		cin>>x>>c;
		ll v=c-'a';
		
		a[i].v=x;
		a[i].id=v;
	}
	ll l=1,r=n;
	while(l<r){
		ll mn=min(a[l].v,a[r].v);
		a[l].v-=mn;
		a[r].v-=mn;
		if(a[l].id!=a[r].id) ans+=mn;
		
		if(a[l].v==0) l++;
		if(a[r].v==0) r--;
		//cout<<mn<<"\n";
	}
//	cout<<l<<" "<<r;
//	cout<<a[l].v<<" "<<a[r].v<<"\n";
	cout<<ans;
	return 0;
}
