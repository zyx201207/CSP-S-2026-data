#include <bits/stdc++.h>
using namespace std;

long long n,x,cnt;
char c;
string s="";

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>c;
		for(int j=0;j<x;j++){
			s+=c;
		}
	}
	for(int i=0;i<ceil(1.0*s.size()/2);i++){
		if(s[i]!=s[s.size()-i]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
