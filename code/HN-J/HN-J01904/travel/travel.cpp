#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string h1="",h2="";
		for(int i=0;i<2;i++){
			h1+=s1[i];
			h2+=s2[i];
		}
		if(h1==h2){
			cout<<1;
			if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')||(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')){
				cout<<1;
				if(abs(s2[2]-s1[2])==1){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000"; 
	}else cout<<"0000";
	return 0;
}
/*
自造样例：
15 01A 06 01B 
0000
02 11A 02 02B
1000
我对不起家长！
对不起老师！
 
*/ 
