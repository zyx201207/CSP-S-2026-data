//GZ-J00613   胡震洋   遵义航天高级中学 
#include <bits/stdc++.h>
using namespace std;
bool f(char a,char b){
	if(a<='C'&&b<='C'){
		if(a+1==b||a-1==b){
			return 1;
		}
	}
	if(a>='D'&&b>='D'){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a,b;
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){//1
		cout<<"1";
		
		if(a==b){//2
			cout<<"1";
			
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){//3
				cout<<"1";
				
				if(f(s1[2],s2[2])==1){
					cout<<"1";
					return 0;
				}
				else {
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			} 
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	} 
	return 0;
}

