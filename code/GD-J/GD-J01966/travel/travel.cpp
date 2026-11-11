#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['E']=2;
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	//车厢 
	int ca=(cr[0]-'0')*10+(cr[1]-'0');
	int cb=(cx[0]-'0')*10+(cx[1]-'0');
	if(ca!=cb)
	{
		cout<<"0000";
		return 0;	
	} 
	else
	{
		cout<<1;
	} 
	//排数 
	int zr=(sr[0]-'0')*10+(sr[1]-'0');
	int zx=(sx[0]-'0')*10+(sx[1]-'0');\
	if(zr!=zx)
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	//座位
	char sa=sr[2];
	char sb=sx[2];
	if(mp[sa]!=mp[sb])
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<1;
	}
	//相邻
//	cout<<sa<<" "<<sb<<"\n";
	if(sa=='C')
	{
		cout<<(sb=='B');
	} 
	else if(sb=='C')
	{
		cout<<(sa=='B');
	}
	else if(sa=='D')
	{
		cout<<(sb=='E');
	}
	else if(sb=='D')
	{
		cout<<(sa=='E');
	}
	else
	{
		cout<<(((sa+1)==sb)or((sa-1)==sb));
	}
	return 0;	
} 
