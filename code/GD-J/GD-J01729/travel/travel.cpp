#include<bits/stdc++.h> 
using namespace std;
string s1,s2,c1,c2;
bool P(string p1,string p2){
	p1.erase(p1.size()-1,1);
	p2.erase(p2.size()-1,1);
	//删除座位号，直接比较车厢号 
	return p1==p2;
}
bool D(){
	char q1=s2[s2.size()-1],q2=c2[c2.size()-1];
	if(abs(q1-q2)==1){
		//若相邻，除 DC外都为1111 
		if((q2!='D'&&q1!='C')&&(q1!='D'&&q2!='C')){
			return true;
		}else{
			return false;
		}
	}else{
		//AC也是同侧 
		if((q2=='A'&&q1=='C')||(q1=='A'&&q2=='C')){
			cout<<"1110";
			exit(0);
		}
	}
	return true;
}
int main(){
	
	
	
	
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1){
		cout<<"0000";
	}else{
		if(P(c2,s2)){
			if(D()){
				cout<<"1111";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}
	return 0;
}
