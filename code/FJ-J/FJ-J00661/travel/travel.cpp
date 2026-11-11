#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char a[3]={'A','B','C'},b[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(c2[0]+c2[1]==s2[0]+s2[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int flag1=0,flag2=0;
	for(int i=0;i<3;i++){
		if(c2[2]==a[i])flag1=1;
		if(s2[2]==a[i])flag2=1;
	}
	if(flag1==flag2)cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(flag1==1&&flag2==1){
		if(c2[2]==s2[2]+1||c2[2]==s2[2]-1)cout<<"1";
		else cout<<"0";
	}
	else cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
