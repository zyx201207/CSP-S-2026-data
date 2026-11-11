#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	b1=c1==c2;
	b2=b1&&s1[0]==s2[0]&&s1[1]==s2[1];
	b3=b2&&((s1[2]-'A'>3)==(s2[3]-'A'>3));
	b4=b3&&(abs(s1[2]-s2[2])==1?(s1[2]!='D'&&s2[2]!='D'):(abs(s1[2]-s2[2])==2&&(s1[2]=='F'||s2[2]!='F')));
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
