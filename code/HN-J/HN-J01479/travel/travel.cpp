#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,n; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(c2[0]==s2[0] and c2[1]==s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(c2[2]<='C' and s2[2]<='C') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(c2[2]-s2[2])==1) cout<<1;
	else{
		cout<<0;
	}
	
	
	
	
	return 0;
}
