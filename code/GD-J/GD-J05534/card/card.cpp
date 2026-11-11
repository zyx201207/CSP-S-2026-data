#include<bits/stdc++.h>
#define lint unsigned long long
using namespace std;
vector<lint> v;
vector<lint> memv;
struct x{
	lint a;
	lint b;
};
int mm;
int q;
bool b;
vector<x> xx;
x aaaa;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		lint ld;
		cin >> ld;
		v.push_back(ld);
	}
	for (int i=0;i<m;i++) {
		xx.push_back(aaaa);
		xx[i].b = 0;
	}
	for(int i=0;i<n;i++) {
		bool bl = 1;
		for(int j=0;i<m;j++) {
			if (v[i] == xx[j].a) bl = 0;
		}
		if (bl) {
			xx[mm].a = v[i];
			mm++;
		}
	}
	for(int i=1;i<=n;i++) {
		memv.clear();
		for(int j=0;j<n;j++) {
			b = 1;
			for(int k=0;k<memv.size();k++) {
				if (memv[k] == v[j]) {
					b=0;
					q=k;
				}
			}
			if(b) {
				memv.push_back(v[j]);
			} else {
				for(int k=q+1;k<memv.size();k++) {
					memv[k] = 0;
				}
			}
			q=0;
		}
		for(int j=0;j<m;j++) {
			for(int k=0;k<memv.size();j++) {
				if(xx[j].a = memv[k]) xx[j].b++;
			}
		}
	}
	for(int i=0;i<m;i++) {
		cout << xx[i].b << ' ';
	}
	return 0;
}
