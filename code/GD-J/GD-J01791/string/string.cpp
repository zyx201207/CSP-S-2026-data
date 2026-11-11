#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node {
	int sz, ch;
};
int n, ans;
vector<node> arr;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++) {
		int sz;
		char ch;
		cin>>sz>>ch;
		arr.push_back({sz, ch-'a'});
	}
	int l = 0, r = arr.size()-1;
	while(l<r) {
		int& sz1 = arr[l].sz, ch1 = arr[l].ch;
		int& sz2 = arr[r].sz, ch2 = arr[r].ch;
		if(ch1 == ch2) {
			if(sz1 == sz2)
				l++, r--;
			else if(sz1 < sz2)
				sz2-=sz1, l++;
			else
				sz1-=sz2, r--;
		} else {
			ans+=min(sz1, sz2);
			if(sz1 == sz2)
				l++, r--;
			else if(sz1 < sz2)
				sz2-=sz1, l++;
			else
				sz1-=sz2, r--;
		}
	}
	cout<<ans;
	return 0;
}
