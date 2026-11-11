#include<bits/stdc++.h>
using namespace std;
string s1_,s2_,c1_,c2_;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1_>>s1_>>c2_>>s2_;
	if(c1_[0]==c2_[0]&&c1_[1]==c2_[1]){
		cout<<'1';
	} 
	else{
		cout<<'0';
	}
	if(c1_[0]==c2_[0]&&c1_[1]==c2_[1]&&s1_[0]==s2_[0]&&s1_[1]==s2_[1]){
		cout<<'1';
		
	} 
	else{
		cout<<'0';
	}
	if((c1_[0]==c2_[0]&&c1_[1]==c2_[1])&&(s1_[0]==s2_[0]&&s1_[1]==s2_[1])&&(s1_[2]>='A'&&s1_[2]<='C'&&s2_[2]>='A'&&s2_[2]<='C')||(s1_[2]>='D'&&s1_[3]<='F'&&s2_[2]>='D'&&s2_[3]<='F')){
			cout<<'1';
	}
	else{
		cout<<'0';
	}
	if((c1_[0]==c2_[0]&&c1_[1]==c2_[1])&&(s1_[0]==s2_[0]&&s1_[1]==s2_[1])&&(s1_[2]-s2_[2]==1||s1_[2]-s2_[2]==-1)){
		cout<<'1';
	} 
	else{
		cout<<'0';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}																													
