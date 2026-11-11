#include<iostream>
#include<cstdio>
#include<String.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	if(s1[0]==c1[0]&&s1[1]==c1[1]){
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			if(s2[2]<='C'&&c2[2]<='C'){
				if(s2[2]=='A'&&c2[2]=='C'){
					cout<<"1110";
					return 0;
				}else if(s2[2]=='C'&&c2[2]=='A'){
					cout<<"1110";
					return 0;
				  }else{
					cout<<"1111"; 
					return 0;
				}
			}else if(s2[2]>='D'&&c2[2]>='D'){
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
}
