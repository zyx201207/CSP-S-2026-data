#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0] and s2[1]==s4[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if( ((s2[2]=='A' or s2[2]=='B' or s2[2]=='C') and (s4[2]=='D' or s4[2]=='F')) or ((s4[2]=='A' or s4[2]=='B' or s4[2]=='C') and (s2[2]=='D' or s2[2]=='F')) ){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(s2[2]-s4[2]==1 or s2[2]-s4[2]==-1) cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
