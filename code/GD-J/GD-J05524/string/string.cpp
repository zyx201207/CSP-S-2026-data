#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x,y;
	cin>>x;
	string s;
	for(int i=0;i<x;i++){
		char c;
		cin>>y>>c;
		for(int j=0;j<y;j++){
			s+=c;
		}
	}
	y=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			y+=1;
		}
	}
	cout<<y;
}
