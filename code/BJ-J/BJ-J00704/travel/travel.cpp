#include <bits/stdc++.h>
using namespace std;

int get_valc(char c)
{
	if(c=='A'||c=='B'||c=='C') return 1;
	return 2;
}

bool is_near(char c,char c1)
{
	if(c>c1) swap(c,c1);
	if((c=='A'&&c1=='B')||(c=='B'&&c1=='C')||(c=='D'&&c1=='E')) return true;
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string c,c1,c2,c3;
	cin>>c>>c1>>c2>>c3;
	if(c==c2)
	{
		cout<<1;
		if(c1[0]==c3[0]&&c1[1]==c3[1]) cout<<1<<(get_valc(c1[2])==get_valc(c3[2]))<<is_near(c1[2],c3[2]);
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
