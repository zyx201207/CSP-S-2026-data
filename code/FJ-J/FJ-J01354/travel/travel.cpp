#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in""r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)printf("%d",1);
	else{
		printf("%d",0);
	} 
	bool f=0;
	if(a2[0]==b2[0]&&a1==b1&&a2[1]==b2[1])printf("%d",1);
	else printf("%d",0);
	if(a2[0]==b2[0]&&a1==b1&&a2[1]==b2[1]&&(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))printf("%d",1),f=1;
	else if(a2[0]==b2[0]&&a1==b1&&a2[1]==b2[1]&&(a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F'))printf("%d",1),f=1;
	else printf("%d",0);
	if(f&&((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='B')))printf("%d",1);
	else if(f&&((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')))printf("%d",1);
	else printf("%d",0);
	return 0;
}
