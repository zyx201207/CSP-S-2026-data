#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool qa(string c1,string s1,string c2,string s2){
	if(c1==c2){
		cout<<1;
		return 1;
	}else{
		cout<<"0000";
		return 0;
	}
}
bool qb(string c1,string s1,string c2,string s2){
	if(qa(c1,s1,c2,s2)){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			return 1;
		}else{
			cout<<"1000";
			return 0;
		}
	}
}
bool qc(string c1,string s1,string c2,string s2){
	if(qb(c1,s1,c2,s2)){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				return 1;
		}else{
			cout<<"1100";
			return 0;
		}
	}
}
bool qd(string c1,string s1,string c2,string s2){
	if(qc(c1,s1,c2,s2)){
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
			cout<<1;
			return 1;
		}else{
			cout<<"1110";
			return 0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	q4(c1,s1,c2,s2);
}
