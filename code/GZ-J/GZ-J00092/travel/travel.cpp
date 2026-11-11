//GZ-J00092 马熙程 贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!="01"&&c1!="16")&&(c2!="01"&&c2!="16"){
		if(c1==c2) cout << 1;
		else cout << 0;
	}
	return 0;
} 
