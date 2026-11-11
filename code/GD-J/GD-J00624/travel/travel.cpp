#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string t1,t2,s1,s2;
	cin>>t1>>s1>>t2>>s2;
	if(t1!=t2)cout<<"0000\n";
	else{
		cout<<"1";
		int a1=s1[1]-'0'+(s1[0]-'0')*10;
		int a2=s2[1]-'0'+(s2[0]-'0')*10;
		if(a1!=a2)cout<<"000\n";
		else {
			cout<<"1";
			if(((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))||(s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')){
				cout<<"1";
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)cout<<"1\n";
				else cout<<"0\n";
			}
			else cout<<"00\n";
		} 
	}
	
	
	return 0;
} 
