#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,c3,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for (int i=0;i<=1;i++){
		c3=c3+s1[i];
		s3=s3+s2[i];
	}
	int ws,ka;
	for (int i=2;i<=2;i++){
		ws=s1[i];
		ka=s2[i];
	}
	if (c1==c2)cout<<1;
	else cout<<0;
	
	if (c1==c2&&c3==s3) cout<<1;
	else cout<<0;
	
	if (((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&c1==c2&&c3==s3) cout<<1;
	else cout<<0;
	
	if (c1!=c2) cout<<0;
	else {
		if ((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) cout<<0;
		else if (s1[2]!=s2[2]&&((ws-ka==1)||(ka-ws==1))&&c3!=s3) cout<<0;
		else if ((s1[2]==s2[2]||((ws-ka==1)||(ka-ws==1))||ka==ws)||((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='B'&&s2[2]<='B')||(s1[2]>='B'&&s2[2]<='C'&&s1[2]<='C'&&s2[2]>='B')))cout<<1;
		else {
			cout<<0;
		}
	}
	return 0;}
//99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
