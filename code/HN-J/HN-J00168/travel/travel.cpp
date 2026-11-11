#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int n=0,m=0;
char h,g;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			n*=10;
			n+=s1[i]-'0';
		}else{
			h=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			m*=10;
			m+=s2[i]-'0';
		}else{
			g=s2[i];
		}
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&n==m){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&n==m){
		if(g>='A'&&g<='C'&&h>='A'&&h<='C'){
			cout<<1;
		}else if((g=='D'&&h=='F')||(g=='F'&&h=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(n==m){
		if((g=='C'&&h=='D')||(g=='D'&&h=='C')){
			cout<<0;
		}else if(max(g,h)-min(g,h)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
