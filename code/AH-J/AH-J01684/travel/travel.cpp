#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2;
	int c1,c2,a1,a2;
	cin>>c1>>s1>>c2>>s2;
	a1=(s1[0]-'0')*10+s1[1]-'0';
	a2=(s2[0]-'0')*10+s2[1]-'0';
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') s1[4]=0;
	else s1[4]=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s2[4]=0;
	else s2[4]=1;
	if(c1==c2){
		cout<<1;
		if(a1==a2) cout<<1;
		else cout<<0;
		if(a1==a2&&s1[4]==s2[4]) cout<<1;
		else cout<<0;
		if(a1==a2&&s1[4]==s2[4]&&abs(s1[2]-s2[2])==1) cout<<1;
		else cout<<0;
	}
	else cout<<"0000";
	return 0;
}
