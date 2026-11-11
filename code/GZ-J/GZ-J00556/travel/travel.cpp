//GZ-J00556 ∫Œ√œ∫Ω ∫Î“„÷–—ß 
#include<bits/stdc++.h>
using namespace std;
int panduan(char a,char b,char c,char d){
	if(a==b){
		if(c==d){
		    return 1;
		}
		else{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
int pa(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			return 1;
		}
		else{
			return 0;
		}
	}if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			return 1;
		}
		else{
			return 0;
		}
	}
}
bool xl(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			if(a+1==b||a-1==b){
				return true;
			}
			else{
				return false;
			}	
		}
	}
	else if(a=='D'||a=='F'){
	    if(b=='D'||b=='F'){
			if(a+1==b||a-1==b){
				return true;
			}
			else{
				return false;
			}
		}
		
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(panduan(c1[0],c2[0],c1[1],c2[1])==1){
		cout<<1;
		if(panduan(s1[0],s2[0],s1[1],s2[1])==1){
			cout<<1;
			cout<<pa(s1[2],s2[2]);
			if(pa(s1[2],s2[2])==1){
				cout<<xl(s1[2],s2[2]);
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<"000";
		}
	}
	if(panduan(c1[0],c2[0],c1[1],c2[1])==0){
		cout<<"0000";
	}
	
	return 0;
} 
