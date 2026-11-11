#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long x;
	string c;
}a[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s;
	
	for (int i = 1; i <= n; i++) {
		cin>>a[i].x>>a[i].c;
	}
	long long ans = 0;
	int l = 1,r = n;
	while (l < r) {
		if (a[l].c == a[r].c) {
			l--;
			r--;
		}
		else {
			long long mn = min(a[l].x,a[r].x);
			a[l].x -= mn;
			a[r].x -= mn;
			if (a[l].x <= 0) l++;
			if (a[r].x <= 0) r--;
			ans += mn;
		}
	}
	cout<<ans;
	return 0;
} 
