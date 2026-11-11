#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s,s1;
	for(int i=1;i<=n;i++){
		long m;
		char c;
		cin>>m>>c;
		for(int j=1;j<=m;j++){
			s=s+c;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		s1=s1+s[i];
	}
	if(s1==s){
		cout<<0;
		return 0;
	}
	long num=0;
	for(int i=s.size()/2;i<=s.size()-1;i++){
		if(s[i]!=s1[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
