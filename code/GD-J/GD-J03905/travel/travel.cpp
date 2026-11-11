#include<bits/stdc++.h>
using namespace std;
bool a_1,a_2,a_3,a_4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a_1=1;
	}
	if(a_1==1){
		if(s1[0]==s2[0]){
			if(s1[1]==s2[1]){
				a_2=1;
			}
		}
	}
	char x1=s1[2],x2=s2[2];
	if(a_2==1){
		if(x1<='C'&&x2<='C'){
			a_3=1;
		}
		if(x1>'C'&&x2>'C'){
			a_3=1;
		}
	}
	if(a_3==1){
		if(x1+1==x2||x2+1==x1){
			a_4=1;
		}
	}
	cout<<a_1<<a_2<<a_3<<a_4;
	return 0;
} 
