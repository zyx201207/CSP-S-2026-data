#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

vector <int> v;
int a[500010];
bool f[300010];
int q[300010];
int n,m;

int main (void) {
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	
	for (int i = 1;i <= n;i++) {
		memset (f,0,sizeof(f));
		while (!v.empty()) v.pop_back();
		for (int j = i;j <= n;j++) {
			if (!f[a[j]]) v.push_back(a[j]),f[a[j]] = true;
			else while (v[v.size() - 1] != a[j] and !v.empty()) f[v[v.size() - 1]] = false,v.pop_back();
		}
		for (int i = 0;i < v.size();i++) q[v[i]]++;
	}
	for (int i = 1;i <= m;i++) cout << q[i] << " ";
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
