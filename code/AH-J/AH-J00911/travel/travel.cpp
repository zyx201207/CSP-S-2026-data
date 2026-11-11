#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int n1,n2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(s1[2]=='D'){s1[2]='G';}
	if(s2[2]=='D'){s2[2]='G';}
	if(n1==n2){cout<<1;}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]-s2[2]>=1&&s1[2]-s2[2]<=2)||(s2[2]-s1[2]>=1&&s2[2]-s1[2]<=2)){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
