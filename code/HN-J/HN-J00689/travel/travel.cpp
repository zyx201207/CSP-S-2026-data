#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1,b1;
char a2[10],b2[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1;
	for(int i=1;i<=3;i++){
		cin>>a2[i];
	}
	cin>>b1;
	for(int i=1;i<=3;i++){
		cin>>b2[i];
	}
	if(a1==b1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[1]==b2[1]&&a2[2]==b2[2]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(((a2[3]=='A'||a2[3]=='B'||a2[3]=='C')&&(b2[3]=='A'||b2[3]=='B'||b2[3]=='C'))||((a2[3]=='D'||a2[3]=='F')&&(b2[3]=='D'||b2[3]=='F'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((a2[3]=='A'&&b2[3]=='B')||(a2[3]=='B'&&b2[3]=='A'||b2[3]=='C')||(a2[3]=='C'&&b2[3]=='B')||(a2[3]=='D'&&b2[3]=='F')||(a2[3]=='F'&&b2[3]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
