#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,L;
ll a[N];
char ch[N];
struct node{
	ll x;
	char ch;
};
vector<node> v1,v2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		L+=a[i];
	}
	ll l=(L+1)/2-(L&1),r=l,i;
	for(i=1;i<=n;i++){
		if(!l)break;
		if(l>=a[i]){
			l-=a[i];
			v1.push_back({a[i],ch[i]});
		}
		else{
			v1.push_back({l,ch[i]});
			break;
		}
	}
	ll k=(a[i]-l)-(L&1);
	if(k){
		v2.push_back({k,ch[i]});
		r-=k;
	}
	i++;
	for(;i<=n;i++){
		if(!r)break; 
		if(r>=a[i]){
			r-=a[i];
			v2.push_back({a[i],ch[i]});
		}
		else{
			v2.push_back({r,ch[i]});
			break;
		}
	}
	r=v2.size()-1,l=0;
	ll ans=0;
	while(r>=0&&l<v1.size()){
		ll k=min(v1[l].x,v2[r].x);
		if(v1[l].ch!=v2[r].ch)ans+=k;
		v1[l].x-=k;
		v2[r].x-=k;
		if(!v1[l].x)l++;
		if(!v2[r].x)r--;
	}
	cout<<ans;
	return 0;
}
