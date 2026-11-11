#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n;
ll ans,r[N],cnt;
string s;
struct node{
	ll a;
	string c;
}w[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>w[i].a>>w[i].c;
		for(ll j=1;j<=w[i].a;j++){
			s=s+w[i].c;
		}
	}
	string aaa=w[1].c;
	ll aa=0;
	for(ll i=2;i<=n;i++){
		if(aaa!=w[i].c){
			aa=1;
		}
	}
	if(aa==0){
		cout<<0;
		return 0;
	}
	for(ll i=0,j=s.size()-1;i<=(s.size()-1)/2,j>=(s.size()-1)/2;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}

