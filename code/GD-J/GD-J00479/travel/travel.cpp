#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string c1,s1,c2,s2;
string ans;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	ans[0]=(c1==c2)+'0';
	string ss1,ss2;
	ss1+=s1[0]+s1[1],ss2+=s2[0]+s2[1];
	ans[1]=(c1==c2&&ss1==ss2)+'0';
	int pr=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
	int px=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	ans[2]=(c1==c2&&ss1==ss2&&pr==px)+'0';
	int f=(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='F'&&s2[2]=='D');
	f|=(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F');
	ans[3]=(c1==c2&&ss1==ss2&&pr==px&&f)+'0';
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
 
