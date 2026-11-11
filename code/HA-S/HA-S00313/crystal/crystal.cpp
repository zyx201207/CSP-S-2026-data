#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=1,c,maxn;
vector<ll> a;
bool DC;
ll dc;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll a1;
	cin>>a1;
	a.push_back(a1);
	cin>>a1;
	a.push_back(a1);
	DC=1;
	dc=a[1]-a[0];
	for(int i=3;i<=n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
		if(a[i-1]-a[i-2]!=dc){
			DC=0;
		}
	}
	
	if(!DC){	//a[i] is not dc
	sort(a.begin(),a.end());
	ll b=1;
	while(m>0){
		c=0;
		c=a[b]-a[b-1];
		c*=(b);
		if(m>=c){
			m-=c;
			maxn=a[b];
			b++;
		}
		else break;
	}
	ans=upper_bound(a.begin(),a.end(),maxn)-a.begin();
	cout<<ans;
	return 0;
}
	else{	//a[i] is dc
			ll x=1;
			while(x<=n && ((x*(x+1)/2)*dc)<=m){
			x++;ans=x;
			}
			cout<<ans;
			return 0;		
	}
	return 0;
}
/*
虽然我想的是贪心，但是这道题本质上并不完全是贪心。
但我写的都是从最小的那个魔法石开始，显然不完全正确。
注意到有性质A B 这两个性质可以从最小贪心进行，故单开if线 
*/
