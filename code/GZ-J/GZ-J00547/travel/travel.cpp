//GZ-J00547 张运航 贵阳市第十九中学 
#include<bits/stdc++.h>
using namespace std;
string s1,s2,z1,z2;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>z1>>s1>>z2>>s2;
	if(z1 == z2){
		cout<<1;
	}else{
		cout<<0;
	}if(z1 == z2&& s1[1] == s2[1]){
		cout<<1;
	}else{
		cout<< 0;
	}if(z1 == z2&& s1[1] == s2[1] ){
		if(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C' ){
			if(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C') cout<<1;
			else cout<<0;
			
		}else if(s1[2] == 'D'||s1[2] == 'E'){
			if( s2[2] == 'D' || s2[2] == 'E'){
				cout<<1;
			}else cout<<0;
			
		}else{
			cout<<0;
		}
	}else{
		cout<< 0;
	}if(z1 == z2&& s1[1] == s2[1] ){
		if(s1[2] == 'A'||s1[2] == 'B' ){
			if( s2[2] == 'A' || s2[2] =='B') cout<<1;
			else cout<<0;
		}else if(s1[2] == 'C'||s1[2] == 'B' ){
			if( s2[2] == 'C' || s2[2] =='B') cout<<1;
			else cout<<0;
		}else if(s1[2] == 'D'||s1[2] == 'E'  ){
			if(s2[2] == 'D' || s2[2] =='E') cout<<1;
			else cout<<0;
			
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	
	return 0;
}
