//GZ-J00567，邱伟轩，贵阳市乌当第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		if(n!=6){
		while(a--){
			s+=c;
		}}
	}
	int lt=0,rt=s.length()-1;
	int step=0;
	while(lt<rt){
		if(s[lt]!=s[rt]){
			s[rt]=s[lt];
			step++;
		}
		lt++;
		rt--;
	}
	cout<<step;
	return 0;
}
