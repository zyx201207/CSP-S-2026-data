#include<bits/stdc++.h>
using namespace std;
char c[50],s[50];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<3;i++)
	    cin>>c[i];
	for(int i=1;i<3;i++)
	    cin>>s[i];
	for(int i=1;i<2;i++){
	    if(c[i]==s[i]) cout<<"1";
	    else if(c[i]!=s[i]) cout<<"0000";
	}	
    return 0;
}
