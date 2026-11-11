#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1;
    for(int i=1;i<=3;i++){
    	cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
    	cin>>s2[i];
	}
    if(c1==c2){
    	cout<<"1";
	}
	else cout<<"0";
		if(c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]){
			cout<<"1";
		}
		else cout<<"0";
		if(c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]>='C'&&s2[3]>='C'||c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]<='D'&&s2[3]<='D'){
			cout<<"1";
		}
		else cout<<"0";
		if(c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]=='A'&&s2[3]=='B'||c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]=='B'&&s2[3]=='A')  cout<<"1";
		else if(c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]=='B'&&s2[3]=='C'||c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]=='C'&&s2[3]=='B')  cout<<"1";
		else if(c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]=='C'&&s2[3]=='D'||c1==c2&&s1[1]==s2[1]&&s2[2]==s1[2]&&s1[3]=='F'&&s2[3]=='D')  cout<<"1";
		else cout<<"0";
	return 0;
}
