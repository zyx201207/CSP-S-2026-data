#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2,x1,x2;
char y1,y2,f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=s1.substr(0,2);
	x2=s2.substr(0,2);
	y1=s1[2];
	y2=s2[2];
	if(y1>='A'&&y1<='C'){
		f1='l';
	}else{
		f1='r';
	}
	if(y2>='A'&&y2<='C'){
		f2='l';
	}else{
		f2='r';
	}
	if(c1==c2){
		if(x1==x2){
			if(f1==f2){
				if(y1-y2==1||y1-y2==-1){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
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
