#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&s1!=s2) {
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			ans[1]='1';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) {
				ans[2]='1';
				int a=s1[2]-s2[2];
				if(a==-1||a==1) {
					ans[3]='1';
				}
			}
		}
	}

	cout<<ans;
	return 0;
}
