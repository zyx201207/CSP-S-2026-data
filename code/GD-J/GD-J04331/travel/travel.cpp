#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
string a,b,c,d;
bool check (char x,char y)
{
	if (x<='C'&&y<='C') return 1;
	if (x>'C'&&y>'C') return 1; 
	return 0;
}
signed main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d; //车厢号 座位号。
	if (a==c) //判断是不是同车厢
	{
		cout<<1; 
		if (b.substr(0,2)==d.substr(0,2)) // 两张车票对应的座位是否在同一节车厢的同一排
		{
			cout<<1;
			if (check(b[2],d[2])) // 且位于过道的同一侧 
			{
				cout<<1;
				if (abs(b[2]-d[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;	
} 
