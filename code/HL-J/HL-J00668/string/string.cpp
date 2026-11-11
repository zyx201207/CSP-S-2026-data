#include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char a;
	ll k,b;
	cin>>k;
	for(ll i=1;i<=k;i++){
		cin>>b>>a;
		for(ll i=1;i<=b;i++){
			s+=a;
		}
	}
	ll cnt=0;
    for(ll i=0;i<=s.length()/2;i++){ 
    	if(s[i]!=s[s.length()-i-1]){
    		cnt++;
    		//cout<<s[i]<<' '<<s[s.length()-i-1]<<endl;
		}
	} 
	cout<<cnt;
}
