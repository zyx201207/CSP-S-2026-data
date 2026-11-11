#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c3;
char c2[4],c4[4];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<"1";
	else cout<<"0";
	int s1=(c2[0]-'0')*10+c2[1]-'0';
	int s2=(c4[0]-'0')*10+c4[1]-'0';
	if(s1==s2 && c1==c3) cout<<"1";
	else cout<<"0";
	int tmp1,tmp2;
	if(c2[2]=='D' || c2[2]=='F') tmp1=1;
	else tmp1=0;
	if(c4[2]=='D' || c4[2]=='F') tmp2=1;
	else tmp2=0;
	if(tmp1==tmp2 && c1==c3 && s1==s2) cout<<"1";
	else cout<<"0";
	int tmp3=c2[2]-'A',tmp4=c4[2]-'A';
	if(abs(tmp3-tmp4)==1 && tmp1==tmp2 && c1==c3 && s1==s2) cout<<"1";
	else cout<<"0";
}
