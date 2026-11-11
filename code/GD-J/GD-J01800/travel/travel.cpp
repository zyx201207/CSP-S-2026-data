#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    cout<<"1";
		    int a=0,b=0;
		    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') a=1;
		    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') b=1;
		    if(a==b) cout<<"1";
		    else cout<<"0";
	    }else cout<<"00";
	    char x=s1[2],y=s2[2];
	    int a=int(s1[0]-'0'*10+s1[1]-'0');
	    int b=int(s2[0]-'0'*10+s2[1]-'0');
	    if(x=='C'&&y=='D'||x=='D'&&y=='C') cout<<"0";
	    else if(a==b&&x-1==y) cout<<"1";
	    else if(a==b&&x+1==y) cout<<"1";
	    else if(a-1==b&&x==y) cout<<"1";
	    else if(a+1==b&&x==y) cout<<"1";
	    else cout<<"0";
	}else{
		cout<<"0000";
	} 
	
	return 0;
} 
