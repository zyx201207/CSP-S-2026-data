#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,ans;
string s=" ";
struct node{
	ll num;
	char s;
}ar[N];
bool check(string s){
	string tem=s;
	reverse(s.begin(),s.end());
	return tem==s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>ar[i].num>>ar[i].s;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=ar[i].num;j++){
			s=s+ar[i].s;
		}
	}
	ll l=1,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	if(n%2==0)cout<<ans;
	else cout<<ans-1;
	return 0;
}
