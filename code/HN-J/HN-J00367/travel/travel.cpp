#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e+10;
string a[10];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	
	if(a[1]==a[3])
	{
		cout<<1;
		int x=(a[2][0]-'0')*10+(a[2][1]-'0');
		int y=(a[4][0]-'0')*10+(a[4][1]-'0');
		if(x==y)
		{
			cout<<1;
			char c1=a[2][2],c2=a[4][2];
			if(('A'<=c1&&c1<='C'&&'A'<=c2&&c2<='C')||('D'<=c1&&c1<='E'&&'D'<=c2&&c2<='E'))
			{
				cout<<1;
				if(c1==c2-1||c2==c1-1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
