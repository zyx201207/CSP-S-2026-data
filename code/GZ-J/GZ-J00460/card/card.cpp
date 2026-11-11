//GZ-J00460 贵阳市第十七中学 徐廷蔚
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[300005];
int now[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	vector<int>v;
	for(int i = 1;i <= n;i ++) {
		memset(now,-1,sizeof now);
		for(int j = i;j <= n;j ++) {
			if(v.size() == 0) {
				v.push_back(a[j]);
				now[a[j]] = 0;
				continue;
			}
			if(now[a[j]] != -1) {
				while(v.size()>now[a[j]])	v.pop_back();
				now[a[j]] = v.size();
				v.push_back(a[j]);
				continue;
			}
			v.push_back(a[j]);
			now[a[j]] = v.size() - 1;
		}
		for(int j = 0;j < v.size();j ++) {
			t[v[j]] ++;
		}
		v.clear();
	}
	for(int i = 1;i <= m;i ++) {
		cout << t[i] << " ";
	}
	return 0;
}
