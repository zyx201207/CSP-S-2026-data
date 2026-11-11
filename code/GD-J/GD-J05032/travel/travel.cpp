#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,pa,pb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	pa+=s1[0]+s1[1],pb+=s2[0]+s2[1];
	if(pa!=pb){
		cout<<"1000";
		return 0;
	}
	int f=0;
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')) f=1;
	else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')) f=1;
	if(f==1){
		cout<<"1100";
		return 0;
	}
	f=0;
	if((s1[2]=='A'&&s2[2]=='B')||s2[2]=='A'&&s1[2]=='B') f=1;
	else if((s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')) f=1;
	else if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')) f=1;
	if(f==1){
		cout<<"1111";
	}else cout<<"1110";
	
	return 0;
}
