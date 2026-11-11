#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
char s1,s2;
int main(){
	//freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	int h=0,k=0;
	for(int i=0;i<2;i++){
		h=h*10+c2[i]-'0';
		k=k*10+c4[i]-'0';
	}
	s1=c2[2];
	s2=c4[2];
	
	if (c1==c3){
		if (h==k){
			if((s1>'C'&&s2>'C')||(s1<='C'&&s2<='C')){
				if(s1>'C'&&s2>'C'){
					cout<<1111;
				}
				if(s1<='C'&&s2<='C'){
					if (s1=='B'||s2=='B'){
						cout<<1111;
					}
					else{
						cout<<1110;
					}
				}
			}
			else{
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
