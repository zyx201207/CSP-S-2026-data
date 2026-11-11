#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string t1,t2;
bool f=0;
char c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{cout<<"0000";return 0;}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='A'&&s1[i]<='Z'){
			c=s1[i];
			s1[i]='X';
			break;
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='A'&&s2[i]<='Z'){
			s=s2[i];
			s2[i]='X';
			break;
		}
	}
	if(s1==s2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s2&&(((c=='D'||c=='F')&&(s=='D'||s=='F'))||((c=='A'||c=='B'||c=='C')&&(s=='A'||s=='B'||s=='C')))){
		f=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f&&(c+1==s||c==s+1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
