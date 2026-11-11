#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<"\n";
#else
#define debug(x)
#endif
#define ll long long
#define PII pair<int,int>
#define vct vector
#define pb push_back
#define int long long

#ifdef LOCAL
bool ____st;
#endif
string c1,s1,c2,s2;
#ifdef LOCAL
bool ____ed;
#endif

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ed-&____st)/(1024*1024)<<"Mib\n";
	double ____ST=clock();
#endif
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]>s2[2])
	{
		swap(s1,s2);
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
#ifdef LOCAL
	double ____ED=clock();
	cerr<<'\n'<<(____ED-____ST)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
