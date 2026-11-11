#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string cl,sl,c2,s2;
	cin>>cl>>sl>>c2>>s2;
	if(cl==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
    }
	if(sl[0]*10+sl[1]==s2[0]*10+s2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((sl[2]=='D'||sl[2]=='F')&&(s2[2]=='F'||s2[2]=='D')||
	((sl[2]=='A'||sl[2]=='B'||sl[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))){
		cout<<1;
	}
		else{
		cout<<"00";
		return 0;
	}
	if(abs(int(sl[2])-int(s2[2]))==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
