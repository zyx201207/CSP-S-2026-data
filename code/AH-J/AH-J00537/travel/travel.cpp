#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c1,c2,t1,t2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;cin.get();cin>>s1;
	cin>>c2;cin.get();cin>>s2;
	if(c1==c2)cout<<1;else cout<<0;
	string p1=s1.substr(0,2),p2=s2.substr(0,2);
	if(c1==c2&&p1==p2)cout<<1;else cout<<0;
	if(s1[2]>='D') t1=1;else t1=2;
	if(s2[2]>='D') t2=1;else t2=2;
	if(c1==c2&&p1==p2&&t1==t2)cout<<1;else cout<<0;
	if(c1==c2&&p1==p2&&t1==t2&&abs(s1[2]-s2[2])==1)cout<<1;else cout<<0;
	return 0;
}
