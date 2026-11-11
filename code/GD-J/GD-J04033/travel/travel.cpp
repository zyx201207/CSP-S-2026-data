#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] and c1[1]==c2[1]) {
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1] ){
			cout<<1;
			if(((s1[2]=='D' and s2[2]=='F') or (s2[2]=='D' and s1[2]=='F')) or (((s1[2]=='A' or s1[2]=='B' or s1[2]=='C' ) and (s2[2]=='A' or s2[2]=='B' or s2[2]=='C')))){
				cout<<1;
				if((s1[2]==s2[2]+1 or s1[2]==s2[2]-1) and ((s1[2]!='C' and s2[2]!='D' ) or (s2[2]!='C' and s1[2]!='D' ))){
					cout<<1;
				}else{
					cout<<0;
				}
	    	}else{
	    		cout<<"00";
			}
		}else cout<<"000"; 
	}else cout<<"0000";
	return 0;
} 
