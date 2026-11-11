#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	int a=s1[2]-'A',b=s2[2]-'A';
	if((a==0&&b==1)||(a==0&&b==2)||(a==1&&b==0)||(a==1&&b==2)||(a==2&&b==0)||(a==2&&b==1)||(a==3&&b==4)||(a==4&&b==3)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	char c=s1[2],d=s2[2];
	if((c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')||(c=='D'&&d=='F')||(c=='F'&&d=='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
