#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int  c1,s1;
	char  c2[2],s2[2];//小R车厢：c1，座位：c2小x车厢：s1，座位：s2
	int same=0;
	cin>>c1>>c2;
	cin>>s1>>s2;
	if(c1!=s1){
	cout<<"0000"; 
	return 0;
	}else same=(same*10)+1; 
	if(c1!=s1&&(c2[0]!=s2[0]&&c2[1]!=s2[1])){
		same=(same*10)+0;
	}else same=(same*10)+1;
	if(c1!=s1&&(c2[0]!=s2[0]&&c2[1]!=s2[1])&&(c2[2]!='A'&&c2[2]!='B'&&c2[2]!='C'&&s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C')||(c2[2]!='D'&&c2[2]!='F'&&s2[2]!='F'&&s2[2]!='D')){
		same=(same*10)+0;
	}else same=(same*10)+1;
	if((c1!=s1&&(c2[0]!=s2[0]&&c2[1]!=s2[1]))&&(c2[2]!='F'&&s2[2]!='D')||(c2[2]!='D'&&s2[2]!='F')||(c2[2]!='A'&&s2[2]!='B')||(c2[2]!='B'&&s2[2]!='A')||(c2[2]!='C'&&s2[2]!='B')||(c2[2]!='B'&&s2[2]!='C')){
		same=(same*10)+0;
	}else same=(same*10)+1;	
	
	
	cout<<same;
	return 0;
}




