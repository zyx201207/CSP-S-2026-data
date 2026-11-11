#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
struct node{
	ll a;
	char c;
};
ll sum;
ll l,r;
ll cnt;
void A(vector<node>& v){
	string s="";
	cin >> r;
	ll a;
	char c;
	for(ll i=0;i<r;i++){
		while(v[i].a--){
			s=s+v[i].c;
		}
	}
	ll l=s.size();
	for(ll i=0,j=l-1;i<j;i++,j--)if(s[i]!=s[j])cnt++;
	cout << cnt;
	return;
}
void B(vector<node>& v){
	r--;
	while(l<r){
		ll mn=min(v[l].a,v[r].a);
		if(v[l].c!=v[r].c)cnt+=mn;
		v[l].a-=mn;
		v[r].a-=mn;
		if(v[l].a==0)l++;
		if(v[r].a==0)r--;		
	}
	cout << cnt;
	return;
}
void solve(){
	cin >> r;
	vector<node> v(r+10);
	for(ll i=0;i<r;i++){
		cin >> v[i].a >> v[i].c;
		sum+=v[i].a;
	}
	if(sum<=10000)A(v);
	else B(v);
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
