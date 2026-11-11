#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5;
int n,a[N],m,ans;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	deque<int>q;
	int cnt=0;
	q.push_back(a[1]);
	for(int i=2; i<=n; i++) {
		int x=cnt+(q.size())*(a[i]-q.back());
		int p=cnt;
		cnt=x;
		if(x<=m) {
			q.push_back(a[i]);
		} else {
			if(x-(a[i]-q.front())<=m) {
				x-=(a[i]-q.front());
				q.pop_front();
				q.push_back(a[i]);
				cnt=x;
			} else cnt=p;
		}
	}
	cout<<q.size();
	return 0;
}
