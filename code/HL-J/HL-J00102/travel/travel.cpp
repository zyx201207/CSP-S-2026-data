#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<1;
		int p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
		if(p1!=p2) cout<<"000";
		else{
			cout<<1;
			char st1=s1[2],st2=s2[2];
			if((st1>'C'&&st2<'D')||(st1<'D'&&st2>'C')) cout<<"00";
			else{
				cout<<1;
				if(abs(st1-st2)==1) cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}