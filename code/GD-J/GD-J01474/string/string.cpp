#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct word{
	ll num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll n;
    cin>>n;
    a[0].num=0,a[0].c=' ';
    for(ll i=1;i<=n;i++){
    	cin>>a[i].num>>a[i].c;
    	if(a[i].c==a[i-1].c){
    		a[i-1].num+=a[i].num;
    		i--;
    		n--;
		}
	}
	ll cnt=0;
	string s=" ";
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[i].num;j++){
			s+=a[i].c;
		}
	}
	ll size=s.size()-1;
	for(ll i=1;i<=size/2;i++){
		if(s[i]!=s[size-i+1])cnt++;
	}
	cout<<cnt;
	return 0;
}
//9
/*

*/
