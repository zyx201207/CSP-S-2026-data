#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[20],s2[20];
int sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2) cout<<"1";
	else cout<<"0"; 
	if(c1==c2&&s1[1]==s2[1]&&s1[2]==s2[2]) cout<<"1";
	else cout<<"0";
	if(c1==c2&&s1[1]==s2[1]&&s1[2]==s2[2]&&(s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')){
		cout<<"1";
		sum=1;
	}else if(c1==c2&&s1[1]==s2[1]&&s1[2]==s2[2]&&(s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')){
		cout<<"1";
		sum=1;
	}
	else cout<<"0";
	if(sum==1&&(int(s1[3])+1==int(s2[3])||int(s1[3])==int(s2[3])+1)) cout<<"1";
	else cout<<"0";
	return 0;
} 
