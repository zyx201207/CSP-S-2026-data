#include<bits/stdc++.h>
using namespace std;
int c_1,c_2,f1,f2,f3,f4;
char s_1[10],s_2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<1;
		f1=1;
	}else {
		cout<<0;
	}if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]&&f1==1){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}if(f1&&f2&&((s_1[2]=='A'&&s_2[2]=='B')||(s_1[2]=='B'&&s_2[2]=='A')||(s_1[2]=='C'&&s_2[2]=='B')||(s_1[2]=='B'&&s_2[2]=='C')||(s_1[2]=='A'&&s_2[2]=='C')||(s_1[2]=='C'&&s_2[2]=='A')||(s_1[2]=='D'&&s_2[2]=='F')||(s_1[2]=='F'&&s_2[2]=='D'))){
		cout<<1;
		f3=1;
	}else{
		cout<<0;
	}
	if(f1&&f2&&f3&&abs(s_1[2]-s_2[2])==1){
		cout<<1;
	}else cout<<0;
	return 0;
}
