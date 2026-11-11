#include<bits/stdc++.h>
using namespace std;
bool isok(char a,char b,int cnt){
	if(a<'D'&&b<'D'&&(cnt<3||cnt>-3))return 1;
	else if(a=='D'||a=='F'&&(b=='D'||b=='F'))return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<'1';
	else cout<<'0';
	int cnt=int(s1[2]-s2[2]);
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&isok(s1[2],s2[2],cnt))cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(isok(s1[2],s2[2],cnt))==1&&(cnt==1||cnt==-1))cout<<'1';
	else cout<<'0';
	return 0;
} 
