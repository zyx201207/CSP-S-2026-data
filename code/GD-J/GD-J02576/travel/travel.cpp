#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int pos1=(c1[0]-'0')*10+(c1[1]-'0'),pos2=(c2[0]-'0')*10+(c2[1]-'0'),r1=(s1[0]-'0')*10+(s1[1]-'0'),r2=(s2[0]-'0')*10+(s2[1]-'0');
	vector<char> ans(4);
	if(pos1==pos2) ans[0]='1';
	else ans[0]='0';
	if(r1==r2&&ans[0]=='1') ans[1]='1';
	else ans[1]='0';
	if(((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))&&ans[1]=='1') ans[2]='1';
	else ans[2]='0';
	if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D'))&&ans[2]=='1') ans[3]='1';
	else ans[3]='0';
	for(int i=0;i<4;i++) cout<<ans[i];
	return 0;
}
