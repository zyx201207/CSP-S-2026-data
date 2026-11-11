#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,v[101];
	v[1]='01b';
	string s2;
	cin>>s2;
	for(int i=0;i<=s2.length();i++){
		if(s2[i]==v[1]){
			cout<<"1";
		}
	}
	return 0;
}
