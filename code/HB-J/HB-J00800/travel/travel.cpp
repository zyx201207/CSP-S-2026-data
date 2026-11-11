#include<bits/stdc++.h>
using namespace std;
char c[3][5],s[3][5];
bool a1=0,a2=0,a3=0,a4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	a1=1;
	for(int i=0;i<2;i++){
		if(c[1][i]!=c[2][i]){
			a1=0;
			break;
		}
	}
	if(a1){
		a2=1;
		for(int i=0;i<2;i++){
			if(s[1][i]!=s[2][i]){
				a2=0;
				break;
			}
		}
		a3=0;
		if(!a2){
			a3=0;
		}
		else{
			if(s[1][2]>='A'&&s[1][2]<='C'&&s[2][2]>='A'&&s[2][2]<='C'){
				a3=1;
			}
			if(s[1][2]>='D'&&s[1][2]<='F'&&s[2][2]>='D'&&s[2][2]<='F'){
				a3=1;
			}
		}
		a4=0;
		if(a3){
			if(s[1][2]+1==s[2][2]||s[1][2]-1==s[2][2]){
				a4=1;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
