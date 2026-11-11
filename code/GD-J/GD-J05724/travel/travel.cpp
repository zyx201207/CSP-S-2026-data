#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool x=true;
    if(c1==c2){
    	cout<<1;	
	}else{
		cout<<0;
		x=false;
	}
	if(x&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
		x=false;
	}
	if(x&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))){
		cout<<1;
	}else{
		cout<<0;
		x=false;
	}
	if(x){
		int a=s1[2]-'A',b=s2[2]-'A';
		if(abs(a-b)<=1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	} 
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
