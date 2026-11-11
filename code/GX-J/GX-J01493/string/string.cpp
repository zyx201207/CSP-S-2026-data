#include <bits/stdc++.h>
using namespace std;
string s;
int n,cot=0,i=0;
void f(string s){
	string rs=s;
	reverse(rs.begin(),rs.end());
	if(rs==s) return ;
	i++;
	if(i>(int)s.size()) i=0;
	s[i]=rs[i];
	cot++;
	f(s);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=0;j<x;j++) s+=c;
	}
	f(s);
	cout<<cot<<s;
	return 0;
}
