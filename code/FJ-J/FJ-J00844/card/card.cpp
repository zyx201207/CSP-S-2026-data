#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b;
int q,w;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(long long i=0;i<=1;i++){
		a+=s1[i];
		b+=s2[i];		
	}
	if(a==b){
		cout<<1;
		q=1;
	}
	else{
		cout<<0;
	}
	if(s1[2]==s2[2]){
		cout<<1;
		w=1;
	}
	else{
		cout<<0;
	}
	if(s1[2]=='A'&&int(s1[2])+1==int(s2[2]))||(s1[2]=='F'&&int(s1[2])-2==int(s2[2]))||(s1[2]='D'&&int(s1[2])+1==int(s2[2]))
	
	return 0;
} 
