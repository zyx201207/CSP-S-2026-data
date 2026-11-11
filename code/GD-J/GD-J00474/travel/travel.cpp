#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define first fi
#define second se 
string s;
int a1,a2,a3,b1,b2,b3; 
char c[114];
bool l[114][114]={
	{},
{0, 0,1,0,0,0},
{0, 1,0,1,0,0},
{0, 0,1,0,0,0},
{0, 0,0,0,0,1},
{0, 0,0,0,1,0}
};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	c['A']=1;
	c['B']=2;
	c['C']=3;
	c['D']=4;
	c['F']=5;
	cin>>s;
	a1=(s[0]-48)*10+s[1];
	cin>>s;
	a2=(s[0]-48)*10+s[1];
	a3=c[s[2]];
	cin>>s;
	b1=(s[0]-48)*10+s[1];
	cin>>s;
	b2=(s[0]-48)*10+s[1];
	b3=c[s[2]];
	if(a1==b1)cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2)cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2&&((a3<=3&&b3<=3)||(a3>=4&&b3>=4)))cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2&&l[a3][b3])cout<<1;
	else cout<<0;
	return 0;
}
