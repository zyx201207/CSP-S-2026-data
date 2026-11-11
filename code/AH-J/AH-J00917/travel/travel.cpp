#include<bits/stdc++.h>
using namespace std;
map<char,int> f;
bool flag;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	f['A']=f['B']=f['C']=1;
	f['D']=f['F']=2;
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	flag=(a1==a2);
	if(flag) cout<<1;
	else cout<<0;
	flag=flag&&(b2[0]+b2[1]==b1[0]+b1[1]);
	if(flag) cout<<1;
	else cout<<0;
	flag=flag&&(f[b1[2]]==f[b2[2]]);
	if(flag) cout<<1;
	else cout<<0;
	flag=flag&&((f[b1[2]]==2)||(b1[2]=='B')||(b2[2]=='B'));
	if(flag) cout<<1;
	else cout<<0;
	return 0;
}
