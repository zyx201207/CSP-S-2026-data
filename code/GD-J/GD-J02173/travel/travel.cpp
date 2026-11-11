#include<bits/stdc++.h>
using namespace std;
string s[5],t[3];
char c[3];
//map<string,bool>bj;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		cin>>s[i];
//		bj[s[i]]++;
		if(i==2||i==4){
			for(int j=0;j<2;j++){
				t[i/2]+=s[i][j];
			}
			c[i/2]=s[i][2];
		}
	}
//	if(bj[s[1]]==2) cout<<"1";
	if(s[1]==s[3]){
		cout<<'1';
			if(t[1]==t[2]){
				cout<<'1';
				if(c[1]<='C'&&c[2]<='C'){
				cout<<'1';
				if(abs(c[1]-c[2])==1) cout<<'1';
				else cout<<0;
			}
			else if(c[1]>'C'&&c[2]>'C'){
				cout<<'1';
				if(abs(int(c[1])-int(c[2]))==1) cout<<'1';
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
    return 0;
}
/*
if嵌套问题,数据结构string 
*/
