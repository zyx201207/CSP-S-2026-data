#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool falg1,falg2,falg3,falg4;
	falg1=falg2=falg3=falg4=true;
	falg1=c1==c2;
	falg2=(s1[0]==s2[0]&&s2[1]==s1[1])&&falg1;
	falg3=!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))&&falg2&&falg1;
	falg4=falg1&&falg2&&falg3&&(abs(s1[2]-s2[2])==1);
	cout<<falg1<<falg2<<falg3<<falg4<<'\n';
	return 0;
}
