#include<bits/stdc++.h>
using namespace std;
string S,T;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	cin>>x>>S>>y>>T;
	if(x!=y)
	{
		cout<<"0000";
		return 0;
	}
	int RowF=(S[0]-'0')*10+(S[1]-'0');
	int RowS=(T[0]-'0')*10+(T[1]-'0');
	if(RowF!=RowS)
	{
		cout<<"1000";
		return 0;
	}
	if(S[2]>='D'&&T[2]>='D')
	{
		cout<<"1111";
		return 0;
	}
	else if(S[2]<='C'&&T[2]<='C')
	{
		if(abs((int)S[2]-T[2])<=1)
		{
			cout<<"1111";
			return 0;
		}
		cout<<"1110";
	}
	else cout<<"1100";
	return 0;
}
