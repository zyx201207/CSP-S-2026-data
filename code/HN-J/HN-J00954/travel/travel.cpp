#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d,e,f;
int sd[7]={1,1,1,2,2};
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	for(int i=0;i<b.length()-1;i++) e+=b[i];
	for(int i=0;i<d.length()-1;i++) f+=d[i];
	if(a==c && e==f)cout<<1;
	else cout<<0;
	if(a==c && e==f && sd[b[2]-'A']==sd[d[2]-'A']) cout<<1;
	else cout<<0;
	if(a==c && e==f && sd[b[2]-'A']==sd[d[2]-'A'] && (abs(b[2]-d[2])==1)) cout<<1;
	else cout<<0;
	return 0;
}
