#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
string s;
ll cnt=0,n;
char lx;
bool allsame=true;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;char x;
		cin>>a>>x;
		for(int i=1;i<=a;i++)s=s+x;
	}
	ll l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r])cnt++;
		l++;
		r--;
	}
	cout<<cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
