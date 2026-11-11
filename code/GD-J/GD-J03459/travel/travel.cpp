#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	string c1,s1,c2,s2; cin>>c1>>s1>>c2>>s2;
	if(s1[2]>s2[2]) swap(c1,c2),swap(s1,s2);
	bool f=true;
	f=f&&(c1==c2); cout<<f;
	f=f&&(s1[0]==s2[0]&&s1[1]==s2[1]); cout<<f;
	f=f&&(s2[2]<='C'||s1[2]>='D'); cout<<f;
	f=f&&(s2[2]-s1[2]==1||s1[2]=='D'&&s2[2]=='F'); cout<<f;
	return 0;
}
