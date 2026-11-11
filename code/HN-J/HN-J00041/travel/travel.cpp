#include <bits/stdc++.h>
using namespace std;

int c1,c2;//车厢号
string s1,s2;//座位号 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//判断是否在同一车厢
	if(c1==c2){
		cout<<1;
	} else{
		cout<<"0000";
		return 0; 
	}
	
	//判断是否在同一车厢的同一行 
	string s3="",s4="";
	//小R 
	for(int i=0;i<s1.size()-1;i++){
		s3+=s1[i];
	}
	//小X 
	for(int i=0;i<s2.size()-1;i++){
		s4+=s2[i];
	}
	if(s3==s4){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}

	//判断是否在同一侧 
	char b1,b2;
	for(int i=s1.size()-1;i<=s1.size()-1;++i){
		b1+=s1[i];
	}for(int i=s2.size()-1;i<=s2.size()-1;++i){
		b2+=s2[i];
	}
//	cout<<"b1:"<<b1<<"b2:"<<b2;
	if(b1>='A'&&b1<='C'&&b2>='A'&&b2<='C'){
		cout<<1;
	}else if(b1>='E'&&b1<='F'&&b2<='E'&&b2<='F'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	//判断是否相邻
	if(b1-b2==1||b2-b1==1){
		cout<<1;
	} else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

