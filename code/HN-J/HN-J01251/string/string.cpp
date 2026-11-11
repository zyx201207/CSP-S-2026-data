#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans=0;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll cnt=0;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		cnt+=a;
		while(a--){
			s1+=c;
		}
	}
	s2=s1;
	ll k=cnt-1;
	for(ll i=0;i<cnt;i++){
		if(i>=cnt/2){
			break;
		}
		if(s1[i]!=s2[k]){
			ans++;
		}
		k--;
	}
	cout<<ans;
	return 0;
}
