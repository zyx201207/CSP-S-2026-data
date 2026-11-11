#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	char ch[9];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ch[1]='1';
	}
	else{
		ch[1]='0';
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
		ch[2]='1';
	}
	else{
		ch[2]='0';
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
		if(s1[2]=='A' || s1[2]=='B' ||s1[2]=='C'){
			if(s2[2]=='A' || s2[2]=='B' ||s2[2]=='C'){
				ch[3]='1';
			}
			else{
				ch[3]='0';
			}
		}
		if(s1[2]=='D' || s1[2]=='F'){
			if(s2[2]=='D' || s2[2]=='F'){
				ch[3]='1';
			}
			else{
				ch[3]='0';
			}
		}
	}
	else{
		ch[3]='0';
	}
	if(c1==c2){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			if(s1[2]=='A' || s1[2]=='B' ||s1[2]=='C'){
				if(s2[2]=='A' || s2[2]=='B' ||s2[2]=='C'){
				    if(s1[2]==s2[2]+1 || s2[2]==s1[2]+1){
			    	    ch[4]='1';
				    }
			        else{
				        ch[4]='0';
			        }
			    }
			    else{
			    	ch[4]='0';
				}
		    }
		    if(s1[2]=='D' || s1[2]=='F'){
		    	if(s2[2]=='D' || s2[2]=='F'){
				    if(s1[2]==s2[2]+1 || s2[2]==s1[2]+1){
			    	    ch[4]='1';
				    }
			        else{
				        ch[4]='0';
			        }
			    }
			    else{
				    ch[4]='0';
			    }
		    }
		}
		else{
			ch[4]='0';
		}
	}
	else{
		ch[4]='0';
	} 
	for(int i=1;i<=4;++i){
		cout<<ch[i];
	}
	return 0;
} 
