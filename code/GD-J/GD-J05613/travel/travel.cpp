#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],s1[3],c2[3],s2[3];
	cin>>c1>>s1>>c2>>s2;
	bool p1=(c1[0]==c2[0] && c1[1]==c2[1]);
	cout<<p1;
	
	char s1n[2]={s1[0],s1[1]},s2n[2]={s2[0],s2[1]};
	bool p2=(s1[0]=s2[0] && s1[1]==s2[1]);
	cout<<(p1 && p2);
	
	bool p3=((s1[2]<='C'&& s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'));
	cout<<(p1 && p2 && p3);
	
	if(p1 && p2 && p3 && abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
		
	return 0;
}
