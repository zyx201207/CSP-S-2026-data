#include<bits/stdc++.h>
using namespace std;
string use_x1,use_y1,use_x2,use_y2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>use_x1>>use_y1>>use_x2>>use_y2;
	if (use_y2<use_y1) swap(use_y1,use_y2);
	if (use_x1==use_x2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if (use_y1.substr(0,2)==use_y2.substr(0,2)) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if (use_y1[2]>='A' && use_y1[2]<='C')
	{
		if (use_y2[2]>='A' && use_y2[2]<='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if (use_y1[2]>='D' && use_y1[2]<='E')
	{
		if (use_y2[2]>='D' && use_y2[2]<='E') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if (use_y1[2]=='D' && use_y2[2]=='E') cout<<1;
	else if ((use_y1[2]=='B' && use_y2[2]=='C') || (use_y1[2]=='A' && use_y2[2]=='B')) cout<<1;
	else cout<<0;
	return 0;
}
