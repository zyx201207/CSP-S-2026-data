#include <bits/stdc++.h>
using namespace std;
long long c1,c2;
char s2[4],s1[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!=01&&c1!=16){
	    cout<<"1";	
	}else cout<<"0";
	 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else cout<<"0";
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='c'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='c'){
			cout<<"1";
			if(s2[2]=='B'||s1[2]=='B'){
				cout<<"1";
			}else cout<<"0";
		} else cout<<"0";
	}else if(s1[2]=='D'||s1[2]=='F'){
		if(s1[1]=='D'||s1[2]=='F'){
			cout<<"11";
		}else cout<<"00";
	}
	return 0;
}  
