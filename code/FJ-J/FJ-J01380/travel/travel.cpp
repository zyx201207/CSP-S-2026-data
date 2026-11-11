#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1=0,f2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]-'A'+1<=3) f1=1;
	if(s2[2]-'A'+1<=3) f2=1;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(f1==f2) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	return 0;
} 
