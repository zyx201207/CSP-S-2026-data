#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s,r;
ll n,a,cnt;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a;
		cin>>c;
		for(ll i=1;i<=a;i++){
			s+=c;
		}
	}
	ll len=s.end()-s.begin();
	for(long long i=len-1;i>=0;i--){
		r+=s[i];
	}
	for(ll i=0;i<len;i++){
		if(s[i]!=r[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}
