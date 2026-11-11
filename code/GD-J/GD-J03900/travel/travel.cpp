#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

string c1,s1,c2,s2;
bool a1,a2,a3,a4;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D') s1[2]='E';
	if(s2[2]=='D') s2[2]='E';
	
	a1=(c1==c2);
	a2=(a1 and s1[0]==s2[0] and s1[1]==s2[1]);
	a3=(a2 and (s1[2]<'D')==(s2[2]<'D'));
	a4=(a3 and abs(s1[2]-s2[2])==1);
	
	cout<<(int)a1<<(int)a2<<(int)a3<<(int)a4;
	
	return 0;
}
