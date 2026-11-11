#include<bits/stdc++.h>
using namespace std;
string wjy_a1="",wjy_s1="",wjy_a2="",wjy_s2="";
int wjy_h(){
	if(wjy_s1[2]>='A'&&wjy_s1[2]<='C'&&wjy_s2[2]>='A'&&wjy_s2[2]<='C'){
		return 1;
	}else if(wjy_s1[2]>='D'&&wjy_s1[2]<='E'&&wjy_s2[2]>='D'&&wjy_s2[2]<='E'){
		return 2;
	}else{
		return 3;
	}
}
bool wjy_u(){
	if(wjy_s1[2]=='A'){
		if(wjy_s2[2]=='B'){
			return true;
		}else{
			return false;
		}
	}
	if(wjy_s1[2]=='B'){
		if(wjy_s2[2]=='A'||wjy_s2[2]=='C'){
			return true;
		}else{
			return false;
		}
	}
	if(wjy_s1[2]=='C'){
		if(wjy_s2[2]=='B'){
			return true;
		}else{
			return false;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>wjy_a1>>wjy_s1>>wjy_a2>>wjy_s2;
	if(wjy_a1==wjy_a2){
		if(wjy_s1[0]==wjy_s2[0]&&wjy_s1[1]==wjy_s2[1]){
			if(wjy_h()==1){
				if(wjy_u()){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}else if(wjy_h()==2&&wjy_s1[2]!=wjy_s2[2]){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
