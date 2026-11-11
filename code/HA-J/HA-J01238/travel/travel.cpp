#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int panding(string x,string y){
	int x1=x[2],y1=y[2];
	if((x1=='A'&&y1=='B')||(x1=='A'&&y1=='C')||(x1=='B'&&y1=='A')||(x1=='B'&&y1=='C')||(x1=='C'&&y1=='B')||(x1=='C'&&y1=='A')){
		return 1;
	}else if((x1=='D'&&y1=='F')||(x1=='F'&&y1=='D')){
		return 1;
	}else{
		return 0;
	}
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2&&c1!="01"&&c1!="16"){
		cout<<1;
	}else{
		cout<<"0000";
			return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
			return 0;
	}
	
	if(panding(s1,s2)==1){
		cout<<1;
	}else{
		cout<<0<<0;
			return 0;
	}
	int s3=s1[2]-'0',s4=s2[2]-'0';
	int k=s3-s4;
	if(k<=1&&k>=-1&&k!=0&&panding(s1,s2)!=0){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	return 0;
}
