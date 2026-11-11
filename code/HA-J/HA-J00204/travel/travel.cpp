#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
	    cout<<"0000"<<'\n';
	    return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000"<<'\n';
		return 0;
	}
	if((s1[2]<=67&&s2[2]<=67)||(s1[2]>=68&&s2[2]>=68)) cout<<"1";
	else{
		cout<<"00"<<'\n';
		return 0;
	} 
	if(s1[2]+s2[2]==131||s1[2]+s2[2]==133||s1[2]+s2[2]==138) cout<<"1";
	else{
		cout<<"0"; 
		return 0;
	}
	return 0;
}
