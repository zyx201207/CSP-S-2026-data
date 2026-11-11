#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],sum;
string s;
char c[200005];
int he[26];
bool hw(string s){
	for(ll l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r]) return false;
	}
	return true;
}
long long count1(string s,ll sum){
	for(ll l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r]) sum++;
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++) s+=c[i];
	}
	if(hw(s)) cout<<0;
	else cout<<count1(s,sum);
	return 0;
}

