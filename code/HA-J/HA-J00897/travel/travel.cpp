#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("r","travel.in",stdin);
//	freopen("w","travel.ont",stdout);
	string q1q,w1w,q2q,w2w;
	cin>>q1q>>w1w>>q2q>>w2w;
	if(q1q!=q2q)
	{
		cout<<"0000";
	}
	else if(w1w[0]*10+w1w[1]!=w2w[0]*10+w2w[1])
	{
		cout<<"1000";
	}
	else if(!(w1w[2]>='D' && w2w[2]>='D' || (w1w[2]<='C' && w2w[2]<='C')))
	{
		cout<<"1100";
	}
	else if(abs(w1w[2]-w2w[2])!=1 && w1w[2]!='D' && w2w[2]!='F' && w2w[2]!='D' && w1w[2]!='F')
	{
		cout<<"1110";
	}
	else
	{
		cout<<"1111";
	}
	return 0;
}
