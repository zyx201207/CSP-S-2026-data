#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool flag2=0;
	if(c1==c2)cout<<1,flag2=1;
	else cout<<0;
	bool flag1=0;
	if(flag2 and s1[0]==s2[0] and s1[1]==s2[1])cout<<1,flag1=1;
	else cout<<0;
	bool flag=0;
	if(flag2 and flag1 and s1[2]<='C' and s2[2]<='C' or s1[2]>'C' and s2[2]>'C')cout<<1,flag=1;
	else cout<<0;
	if(flag2 and flag1 and flag and abs(int(s1[2])-int(s2[2]))==1)cout<<1;
	else cout<<0;
	return 0;
}
