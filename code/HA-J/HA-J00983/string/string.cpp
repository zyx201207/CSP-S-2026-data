#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=0;j<x;j++){
			s+=a;
		}
	}
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[i-1]) flag=false;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
			//cout<<s[i]<<' '<<s[s.size()+1-i]<<' '<<i<<endl;
		}
	}
	cout<<cnt;
	//cout<<' '<<s.size()<<' '<<s;
	return 0;
}