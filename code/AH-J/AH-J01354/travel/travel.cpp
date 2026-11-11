#include<bits/stdc++.h>
using namespace std; 
string s,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>s2>>s3>>s4;
	int a=(s[0]-'0')*10+(s[1]-'0');
	int b=(s2[0]-'0')*10+(s2[1]-'0');
	int x=(s2[2]-'A');
	int c=(s3[0]-'0')*10+(s3[1]-'0');
	int d=(s4[0]-'0')*10+(s4[1]-'0');
	int y=(s4[2]-'A');
	if(x>y) swap(x,y);
	if(a!=c) cout<<"0000";
	else if(b!=d) cout<<"1000";
	else if(x==0&&y==3||x==0&&y==5||x==1&&y==3||x==1&&y==5||x==2&&y==3||x==2&&y==5) cout<<"1100";
	else if(x==0&&y==2) cout<<"1110";
	else cout<<"1111";
	return 0;
}
