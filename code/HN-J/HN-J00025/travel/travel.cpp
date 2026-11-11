#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<1;
	else cout<<0;
	int s1=(c2[0]-'0')*10+(c2[1]-'0'),s2=(c4[0]-'0')*10+(c4[1]-'0');
	if((c1==c3) && (s1==s2)) cout<<1;
	else cout<<0;
	char k1,k2;
	k1=c2[2],k2=c4[2];
	if((c1==c3) && (s1==s2) && ((k1<='C' && k2<='C') || (k1>='D' && k2>='D'))) cout<<1;
	else cout<<0;
	if((c1==c3) && (s1==s2) && ((k1<='C' && k2<='C') || (k1>='D' && k2>='D')) && k1+1==k2) cout<<1;
	else cout<<0;
	return 0;
}
