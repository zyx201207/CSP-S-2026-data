#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[5]={0,0,0,0,0};
int ns1,ns2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans[0]=1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) ans[1]=1;
	else{
		cout<<"1000"<<endl;
		return 0;
	}
	if((s1[2]=='A' && s2[2]=='B') ||(s1[2]=='B' && s2[2]=='A')){
		ans[2]=1;
		ans[3]=1;
	}
	if((s1[2]=='B' && s2[2]=='C') ||(s1[2]=='C' && s2[2]=='B')){
		ans[2]=1;
		ans[3]=1;
	}
	if((s1[2]=='C' && s2[2]=='A') ||(s1[2]=='A' && s2[2]=='C')){
		ans[2]=1;
		ans[3]=0;
	}
	if((s1[2]=='E' && s2[2]=='D') ||(s1[2]=='D' && s2[2]=='E')){
		ans[2]=1;
		ans[3]=1;
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
