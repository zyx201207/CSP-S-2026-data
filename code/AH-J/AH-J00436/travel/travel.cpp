#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int pd(char x){
		if(x=='A'||x=='B'||x=='C'){
			return 1;
		}
		return 2;
}
bool check(char x,char y){
	if(pd(x)+pd(y)!=3){
			return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		string t1=s1.substr(0,2);
		string t2=s2.substr(0,2);
		if(t1==t2){
			f2=1;
			char c11=s1[2],c22=s2[2];
			if(c22=='F'){
					c22='E';
			}
			if(check(c11,c22)){
				f3=1;
				if(c22-c11==1||c22-c11==-1){
					f4=1;
				}
			}	
		}
	}
	cout<<f1<<f2<<f3<<f4; 
	return 0;
}
