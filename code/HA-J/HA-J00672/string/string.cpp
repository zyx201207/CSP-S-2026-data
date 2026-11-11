#include<bits/stdc++.h>
#define endl '\n'
#define debug cout << "qwq" << endl;
#define int long long
using namespace std;

const int N = 2e5 + 10;
struct node{
	int cnt;
	char c;
}a[N];
int n, res, len, mid;

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i].cnt >> a[i].c, len += a[i].cnt;
	int l = 1, r = n;
	while(l <= r){
		if(a[l].cnt >= a[r].cnt){
			if(a[l].c != a[r].c) res += a[r].cnt;
			a[l].cnt -= a[r].cnt;
			r --;
		}else{
			if(a[l].c != a[r].c) res += a[l].cnt;
			a[r].cnt -= a[l].cnt;
			l ++;
		}
	}
	 
	cout << res << endl;

	return 0;
}
/*
如果两边都没有到中间，就随便搞一下就好了
最后两边一定会都跳到mid的
然后，在mid内部，显然不用改
那好像是好做的 
*/ 
