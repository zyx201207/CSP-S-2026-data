#include<bits/stdc++.h>
using namespace std;
int f(string x,string y){
	if(x[0]<='C'&&y[0]<='C'){
		return 1;
	}else if(x[0]>='D'&&y[0]>='D'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	string ss1,ss2;
	ss1=s1.substr(0,2);
	ss2=s2.substr(0,2);
	if(ss1==ss2&&c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	string s1s,s2s;
	s1s=s1.substr(2,1);
	s2s=s2.substr(2,1);
	if((ss1==ss2)&&(f(s1s,s2s)&&c1==c2)){
		cout<<1;
	}else{
		cout<<0;
	}
	int ss1s,ss2s;
	ss1s=s1s[0]-65;
	ss2s=s2s[0]-65;
	if((abs(ss1s-ss2s)==1)&&(ss1s+ss2s!=5&&(ss1==ss2&&(f(s1s,s2s)&&c1==c2)))){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
