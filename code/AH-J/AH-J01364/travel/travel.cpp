#include<bits/stdc++.h>
using namespace std;
int st(string s){
	int sa=0;
	if(s[0]==0) sa=s[1]-48;
	else sa=(s[0]-48)*10+(s[1]-48);
	return sa;
}
int str(string ss){
	int x;
	if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'){
		x=1;
	}else if(ss[2]=='D'||ss[2]=='F'){
		x=0;
	}
	return x;
}
int stro(string strq){
	int x;
	x=strq[2]-'A';
	return x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,cc;
	string s,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}else{
		cout<<0;
	}
	int p=st(s);
	int q=st(ss);
	if(c==cc&&p==q){
		cout<<1;
	}else{
		cout<<0;
	}
	int u=str(s);
	int v=str(ss);
	if(c==cc&&p==q&&(!(u^v))){
		cout<<1;
	}else{
		cout<<0;
	}
	int m=stro(s);
	int n=stro(ss);
	if(c==cc&&p==q&&((m+1==n)||(m-1==n))&&(!(u^v))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
