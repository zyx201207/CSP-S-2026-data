#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a1,a2;
	cin>>s1>>s2>>a1>>a2;
	if(s1!=a1){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	char s32=s2[0],s31=s2[1],a32=a2[0],a31=a2[1];
	if(s32==a32&&s31==a31) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s2[2]=='C'&&a2[2]=='D')||(s2[2]=='D'&&a2[2]=='C')){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if(abs((s2[2]-'A')-(a2[2]-'A'))==1) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
