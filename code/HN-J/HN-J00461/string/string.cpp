#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	while(n--){
		cin>>x>>c;
		for(int i=0;i<x;i++){
			s+=c;
		}
	}
	
	for(int i=0,j=s.size()-1;i<=s.size()/2,j>=s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 


