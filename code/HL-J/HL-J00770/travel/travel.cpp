#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string a,b,c,d,e,f;
char t1,t2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	e+=b[0];e+=b[1];
	f+=d[0];f+=d[1];
	t1=b[2];t2=d[2];
//	cout<<e<<endl<<f<<endl<<t1<<endl<<t2<<endl;
	if(a==c) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	
	if(e==f) cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	
	if(((t1<='C'&&t1>='A')&&(t2<='C'&&t2>='A'))||((t1<='F'&&t1>='D')&&(t2<='F'&&t2>='D'))) cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	
	if((t1+1==t2)||(t1-1==t2)) cout<<1;
	else cout<<0;
	return 0;
}
/*

*/

