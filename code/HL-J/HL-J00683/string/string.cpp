#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);       
	freopen("string.out","w",stdout);
	ll n;  
	cin>>n;
	vector<char>aaa;
	for(int i=0;i<n;i++){
		ll x;
		char y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			aaa.push_back(y);	
		}
	}
	ll l=0,r=aaa.size()-1;
	ll cnt=0;
	while(l<=r){
		if(aaa[l]!=aaa[r])cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
