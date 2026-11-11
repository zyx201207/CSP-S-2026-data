#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	vector<char> s,v;
	for(int i=0;i<n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=0;j<x;j++){
			s.push_back(a);
		}
	}
	v=s;
	reverse(s.begin(),s.end());
	for(int i=(s.size()+3)/2-1;i<s.size();i++){
		if(v[i]!=s[i]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
