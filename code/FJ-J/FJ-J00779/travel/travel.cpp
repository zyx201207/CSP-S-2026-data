#include<bits/stdc++.h>
using namespace std;
char a1[3],a2[3],b1[4],b2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1])cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(a2[2]=='A'||a2[2]=='C'){
		if(b2[2]=='B')cout<<1;
		else{
			cout<<0;
			return 0;
		}
	}else if(a2[2]=='B'){
		if(b2[2]=='A'||b2[2]=='C')cout<<1;
		else{
			cout<<0;
			return 0;
		}
	}else if(a2[2]=='D'||a2[2]=='E'){
		if(b2[2]=='D'||b2[2]=='E'){
			cout<<1;
		}else{
			cout<<0;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
  return 0;
}
