#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,c2;
	cin>>c1>>c2;
	char s1[4],s2[4];
	
	if(c1==c2&&c1!='01'&&c1!='17'&&c2!='01'&&c2!='17'){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	for(int i=0;i<3;i++){
		cin>>s1[i];
		}
		for(int i=0;i<3;i++){
			cin>>s2[i];
		}
		if(s1[0]==s2[0]) cout<<'1';
		else cout<<'0';
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
			cout<<'0';
		}
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(s1[2]==s2[2]+1){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
		

	return 0;
}
