#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string t1,s1,t2,s2;
	cin>>t1>>s1>>t2>>s2;
	if(t1==t2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			
			cout<<"1";
			char a=s1[2],b=s2[2];
			if(((a=='D'||a=='F')&&(b=='D'||b=='F'))||((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))){
				cout<<"1";
				if(a=='D'){
					if(b=='F')cout<<"1";
					else cout<<"0";
				}else if(a=='F'){
					if(b=='D')cout<<"1";
					else cout<<"0";
				}else{
					if(a==b-1||a==b+1)cout<<"1";
					else cout<<"0";
				}
				
			}else{
				cout<<"00";
			}
		}else{
			
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
