#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int t[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])t[0]=1;
	if(t[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1])t[1]=1;
	if(t[1]==1&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))t[2]=1;
	else if(t[1]==1&&(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))t[2]=1;
	if(t[2]==1&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))t[3]=1;
	for(int i=0;i<=3;i++){
		cout<<t[i];
	}
	return 0;
} 
