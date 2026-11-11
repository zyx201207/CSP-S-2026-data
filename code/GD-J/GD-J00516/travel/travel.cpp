#include<bits/stdc++.h>
#define int long long
using namespace std;
set<pair<char,char> > near;
set<char> l;
string a,b,c,d,ans;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	l.insert('A');
	l.insert('B');
	l.insert('C');
	near.insert({'A','B'});
	near.insert({'B','C'});
	near.insert({'D','F'});
	near.insert({'B','A'});
	near.insert({'C','B'});
	near.insert({'F','D'});
	ans = "0000";
	if(a == c){
		ans[0] = '1';
		if(b[0] == d[0] && b[1] == d[1]){
			ans[1] = '1';
			if(l.count(b[2]) == l.count(d[2])){
				ans[2] = '1';
				if(near.count({b[2],d[2]}))
					ans[3] = '1';
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

