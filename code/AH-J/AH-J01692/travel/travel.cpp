#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) a[1]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) a[2]=1;
	
	if(s1[2]=='A'&&s2[2]=='B') a[3]=1,a[4]=1;
	else if(s1[2]=='B'&&s2[2]=='A') a[3]=1,a[4]=1;
	else if(s1[2]=='A'&&s2[2]=='C') a[3]=1;
	else if(s1[2]=='C'&&s2[2]=='A') a[3]=1;
	else if(s1[2]=='B'&&s2[2]=='C') a[3]=1,a[4]=1;
	else if(s1[2]=='C'&&s2[2]=='B') a[3]=1,a[4]=1;
	else if(s1[2]=='D'&&s2[2]=='F') a[3]=1,a[4]=1;
	else if(s1[2]=='F'&&s2[2]=='D') a[3]=1,a[4]=1;
	int flag=1;
	cout<<a[1];
	if(a[1]==0) flag=0;
	for(int i=2;i<=4;i++){
		if(flag==1) cout<<a[i];
		else cout<<"0";
		if(a[i]==0) flag=0;
	}
	return 0;
}
