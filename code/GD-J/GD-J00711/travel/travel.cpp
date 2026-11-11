#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) cout<<"00";
			else{
				cout<<1;
				if(abs((int)s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}
		} 
		else{
			cout<<"00";	
			int x=s1[1]-'0'+(s1[0]-'0')*10,y=s2[1]-'0'+(s2[0]-'0')*10;
			if(abs(x-y)==1&&abs((int)s1[2]-s2[2])==0) cout<<1;
			else cout<<0;
		} 
	} 
	else cout<<"0000";
	return 0;
}
