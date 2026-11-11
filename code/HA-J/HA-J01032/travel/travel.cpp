#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int flag=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		flag=1;
		cout<<1;
	}
	else cout<<0;
	int x=0;
	for(int i=0;i<2;i++){
		if(s2[i]==s4[i])x++;
	}
	if(flag==1&&x==2)cout<<1;
	else cout<<0;
	if(flag==1&&x==2&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'&&s4[2]=='A'||s4[2]=='B'||s4[2]=='C')cout<<1;
	else if(flag==1&&x==2&&(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D'))cout<<1;
	else cout<<0;
	if(s2[2]=='C'&&s4[2]=='D'||s2[2]=='D'&&s4[2]=='C')cout<<0;
	else if(flag==1&&x==2&&s2[2]+1==s4[2]||s2[2]-1==s4[2])cout<<1;
	else cout<<0;
	return 0;
}
