#include<bits/stdc++.h>
using namespace std;
int main(){
	fre("travel.in","r",stdin);
	fre("travel.out","r",stdin);
	char c1[1001],s1[1001],c2[1001],s2[1001];
	cin>>c1[1001]>>s1[1001]>>c2[1001]>>s2[1001];
	if(c1[1]==c2[1]){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<"1";
			if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C'){
				cout<<"111";
			}else if(s2[3]=='A'&&s1[3]=='B'||s2[3]=='B'&&s1[3]=='C'){
				cout<<"111";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
