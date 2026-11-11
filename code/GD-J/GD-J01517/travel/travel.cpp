#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int toIdx(string x){
	int res=(x[0]-'0')*10+(x[1]-'0');
	return res;
}
bool check(char a,char b){
	return (a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F');
}
bool pd(char a,char b){
	if(a=='A'&&b=='B')return true;
	else if((a=='B'&&a=='C')||(a=='B'&&b=='A'))return true;
	else if(a=='C'&&b=='B')return true;
	else if(a=='D'&&b=='F')return true;
	else if(a=='F'&&b=='D')return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		int a=toIdx(s1),b=toIdx(s2);
		if(a==b){
			if(check(s1[2],s2[2])){
				if(pd(s1[2],s2[2])){
					cout<<1111;
				}else cout<<1110;
			}else cout<<1100;
		}else{
			cout<<1000;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
