#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<string> s;
vector<string> s1;
vector<string> s2;
ll tmp=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		ll a;
		string c;
		cin>>a>>c;
		for(ll j=0;j<a;j++){
			s.push_back(c);
		}
		tmp+=a;
	}
	if(tmp%2==0){
		for(ll i=tmp-1;i>=0;i--){
			s1.push_back(s[i]);
			cout<<s1[i]<<endl<<endl;
		}
		for(ll i=s.size()-1;i>=tmp;i--){
			s2.push_back(s[i]);
			cout<<s2[i]<<endl;
		}
	}
	for(ll i=s.size()-1;i>=0;i--){
		s1.push_back(s[i]);
	}
	ll cnt=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]!=s1[i]){
			cnt++;
		}
	}
	if(cnt==0){
		cout<<0<<endl; 
	}else{
		if(cnt%2!=0){
			cout<<cnt/2+1<<endl;
		}else{
			cout<<cnt/2<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
