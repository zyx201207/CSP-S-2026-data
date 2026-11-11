#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2?1:0)<<(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2?1:0)<<(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2&&(s1[2]<='C')==(s2[2]<='C')?1:0)<<(c1==c2&&(s1[2]<='C')==(s2[2]<='C')&&s1[0]==s2[0]&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==1?1:0);
	return 0;
}
