#include<bits/stdc++.h>
using namespace std;

bool check1(string s1, string s2)
{
	int Rp=(s1[0]-'0')*10+(s1[1]-'0'), Xp=(s2[0]-'0')*10+(s2[1]-'0');
	if(Rp == Xp) return 1;
	else return 0;
}

bool check2(string c1, string c2)
{
	return c1 == c2;
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("traval.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	string c1, c2, s1, s2;
	cin>>c1>>s1>>c2>>s2;
	bool vis2 = check2(c1, c2);
	cout<<vis2;
	if(!vis2)
	{
		cout<<"000";
		return 0;
	}
	bool vis = check1(s1, s2);
	cout<<vis;
	if(!vis)
	{
		cout<<"00";
		return 0;
	}
	char Rch = s1.back(), Xch = s2.back();
	if(vis && Rch <= 'C' && Xch <= 'C') cout<<1;
	else if(vis && (Rch >= 'D' && Rch <='F') && (Xch >= 'D' && Xch <='F')) cout<<1;
	else cout<<0;
	
	//cout<<"\n("<<Rch<<","<<Xch<<")\n";
	
	if(vis && Rch <= 'C' && Xch <= 'C' && (Rch + 1 == Xch || Rch == Xch + 1)) cout<<1;
	else if(vis && Rch <='F' && Xch <= 'F' && ((Rch == 'D' && Xch == 'F') || (Rch == 'F' && Xch == 'D'))) cout<<1;
	else cout<<0;
}
