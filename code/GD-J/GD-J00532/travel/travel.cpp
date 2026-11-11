#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
void read(int &x)
{
	cin>>x;
	if(!x)cin>>x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char x,y;
	read(c1);read(s1);cin>>x;
	read(c2);read(s2);cin>>y;
	cout<<(c1==c2?'1':'0');
	cout<<((c1==c2)&&(s1==s2)?'1':'0');
	cout<<((c1==c2)&&(s1==s2)&&(mp[x]==mp[y])?'1':'0');
	bool ans=false;
	if((c1==c2)&&(s1==s2)&&(mp[x]==mp[y]))
	{
		if(x==y+1||y==x+1||(x=='D'&&y=='F')||(x=='F'&&y=='D'))
			ans=true;
	}
	else if((c1==c2)&&x==y)
		if(s1==s2+1||s2==s1+1)
			ans=true;
	cout<<(ans?'1':'0');
	// string c1,s1,c2,s2;
	// cin>>c1>>s1>>c2>>s2;
	// cout<<bool(c1==c2)<<bool(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]);
	// cout<<bool(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&mp[s1[2]]==mp[s2[2]]);
	// if(c1==c2)
	// {
	// 	if(s1[2]=='A')
	// 	{
	// 		if(s2[2]=='B'&&s1[0]==s2[0]&&s1[1]==s2[1])
	// 	}
	// }
	return 0;
}