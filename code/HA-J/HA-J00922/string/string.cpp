#include<bits/stdc++.h> 
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int x;
	string s;
	cin>>x;
	long long len=0;
	for(int i=0;i<x;i++){
		int o;
		char p;
		cin>>o>>p;
		len+=o;
		while(o--){
			s+=p;
		}
	}
	long long l=0,r=len-1;
	long long cnt=0;
	while(l<r){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
