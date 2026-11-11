#include <bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if (s1==s2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		x+=c1[i];
		y+=c2[i];
	}
	if (x==y) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char r=c1[2],l=c2[2];
	if (r=='A' && l=='B' || r=='B' && l=='A' || r=='A' && l=='C' || r=='C' && l=='A' || r=='B' && l=='C' || r=='C' && l=='B' || l=='D' && r=='E' || l=='E' && r=='D') cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if (r=='A' && l=='B' || r=='B' && l=='A' || r=='B' && l=='C' || r=='C' && l=='B' || l=='D' && r=='E' || l=='E' && r=='D') cout<<"1";
	else cout<<"0";
	return 0;
}
