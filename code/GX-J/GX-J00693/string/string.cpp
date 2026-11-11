#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int count_,a,c;
	cin>>count_;
	string yuanwen,b,fanwen;
	for(int i=1;i<=count_;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			yuanwen+=b;
		}
	}
	for(int i=yuanwen.size();i>=1;i--){
		fanwen+=yuanwen[i];}
	for(int i=yuanwen.size();i>=1;i--){
		if(yuanwen[i]!=fanwen[i]){
			c+=1;}
	}
	cout<<c;
	return 0;
}
