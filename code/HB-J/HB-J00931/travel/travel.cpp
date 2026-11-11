#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,aa,bb;
    cin>>a>>b>>aa>>bb;
    if(a==aa){
	    if((b[0]==bb[0])||(b[1]==bb[1])){
		    if(((b[2]=='A')&&(bb[2]=='B'))||((b[2]=='A')&&(bb[2]=='C'))||((b[2]=='B')&&(bb[2]=='A'))||((b[2]=='B')&&(bb[2]=='C'))||((b[2]=='C')&&(bb[2]=='A'))||((b[2]=='C')&&(bb[2]=='B'))||((b[2]=='D')&&(bb[2]=='F'))||((b[2]=='F')&&(bb[2]=='D'))){
			    if(((b[2]=='A')&&(bb[2]=='B'))||((b[2]=='B')&&(bb[2]=='A'))||((b[2]=='B')&&(bb[2]=='C'))||((b[2]=='C')&&(bb[2]=='B'))||((b[2]=='D')&&(bb[2]=='F'))||((b[2]=='F')&&(bb[2]=='D'))) cout<<"1111";
			    else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
    return 0;
}
