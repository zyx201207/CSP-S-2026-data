#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(((a>='A'&&a<='C')&&(b>='A'&&b<='C'))||((a>='D'&&a<='F')&&(b>='D'&&b<='F'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(char(a+1)==b||char(a-1)==b){
		cout<<1;
	}else{
		cout<<"0";
	}
	
	return 0;
} 
