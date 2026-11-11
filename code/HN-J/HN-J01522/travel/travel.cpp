#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else cout<<"0";
	int x=(s1[2]-'C'),y=(s2[2]-'C');
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(x>0)==(y>0)) cout<<"1";
	else cout<<"0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(x>0)==(y>0)&&abs(x-y)<=1) cout<<"1";
	else cout<<"0";
	return 0;
}
