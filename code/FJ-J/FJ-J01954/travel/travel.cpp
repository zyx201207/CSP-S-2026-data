#include<bits/stdc++.h>
#define int long long
#define TNF 0x3f3f3f3f3f3f3f3f
#define endl '\n' 
using namespace std;
using pii=pair<int,int>;
string n,m,a,b;
void d()
{
	cin>>n>>m>>a>>b;
	if(n[1]==a[1])cout<<1;
	else 
	{
		cout<<"0000";
		return ;
	}
	if(m[0]*10+m[1]==b[0]*10+b[1])
	{
		cout<<1;
		if(m[2]>='A'&&m[2]<='C'&&b[2]>='A'&&b[2]<='C')cout<<1;
		else if(m[2]>='D'&&m[2]<='F'&&b[2]>='D'&&b[2]<='F')cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	int w=m[0]*10+m[1];
	int r=b[0]*10+b[1];
	int q=m[2]-'A'+1;
	int e=b[2]-'A'+1; 
	if(m[2]>='A'&&m[2]<='C'&&b[2]>='A'&&b[2]<='C')
	{
	//	cout<<51;
		if(e+1==q&&w==r||e-1==q&&w==r||w+1==r&&e==q||w-1==r&&e==q)cout<<1;
		else cout<<0;
	}
	else 
	if(m[2]>='D'&&m[2]<='F'&&b[2]>='D'&&b[2]<='F')
	{
		if(e+1==q||e-1==q||w+1==r||w-1==r)cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t; 
	while(t--)d();
}
