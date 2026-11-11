//GZ-J00501 ¸ß´ï
#include<bits/stdc++.h>
using namespace std;
int a , b ;
string s ,s1;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s >> b >>s1;
	if(a==b){
		cout << 1;
	}
	else{
		cout<<"0000"; 
		return 0 ;
	}
	if(s[0]==s1[0]&&s[1]==s1[1]){
		cout <<  1 ;
	}
	else{
		cout << "000" ;
		return 0;
	}	
	if(s[2]>='A'&&s[2]<='C'&&s1[2]>='A'&&s1[2]<='C'){
			cout << 1 ;
	}
	else if(s[2]=='D'&&s1[2]=='F'||s1[2]=='D'&&s[2]=='F'){
		cout << "11" ;
		return 0 ;
		}
		else{
		cout << "00" ;
		return 0 ;
		}
	if(s[2]>='A'&&s[2]<='C'&&s[2]+1==s1[2]||s[2]>='A'&&s[2]<='C'&&s[2]-1==s1[2]){
		cout<< 1 ;
	}
	else{
	cout << "0" ;
	}
	return 0 ;
}
