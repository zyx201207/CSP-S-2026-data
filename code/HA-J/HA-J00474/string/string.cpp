#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_h(string s){
	for(int l=0,r=int(s.size()-1);l<=r;l++,r--){
		if(s[l]!=s[r]){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll a,sum_=0;
	char b;
	string s,s1;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	if(is_h(s)){
		cout<<0;
		return 0;
	}else{
		for(int i=0;i<int(floor(s.size()/2.0));i++){
			s1+=s[i];
		}
		for(int i=int(s.size())-1,j=0;i>=int(ceil(s.size()/2.0));i--,j++){
			if(s[i]!=s1[j]){
				sum_++;
			}
		}
	}
	cout<<sum_;
	return 0;
}
