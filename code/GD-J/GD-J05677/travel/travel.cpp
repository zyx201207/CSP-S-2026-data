#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//是否在同一个车厢 
		cout<<"1";
	}else{
		cout<<"0000";
		return 0; 	
	}
	
	if(s1[0] == s2[0] && s1[1]==s2[1]){//是否在同一排 
		cout<<"1";
		char a=s1[2],b=s2[2];
		
		if(a=='D'&&b=='F'||a=='F'&& b=='D'){
			cout<<"11";
		}else if(a>='A' && a<='C'&&b>='A'&&b<='C'){
			cout<<"1";
			if(a-b==1 || b-a==1){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
		return 0;
	}	
	

	return 0;
}
