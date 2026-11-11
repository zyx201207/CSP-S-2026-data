#include<bits/stdc++.h>
#include<stack>
using namespace std;
int n,m;
stack<int> a;

int pm[500005];//500005
int c[300005];//300005
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool k = 1;
	for(int i = 1; i<=n; i++) {
		scanf("%d",&pm[i]);
		if(pm[i-1] > pm[i]) {
			k = 0;
		}
	}
	for(int o = 1; o<=n; o++) {
		bool b[300005];//300005
		for(int i = 1; i<=n; i++) b[i] = 0;
		for(int i = o; i<=n; i++) {
			if(b[pm[i]] == 0) {
				a.push(pm[i]);
				b[pm[i]] = 1;
			} else {
				int x = 0;
				while(a.top() != pm[i]) {
					x = a.top();
					a.pop();
					b[x] = 0;
				}
			}
		}
		while(!a.empty()) {
			c[a.top()]++;
			a.pop();
		}
	}
	for(int i = 1; i<=m; i++) {
		printf("%d ",c[i]);
	}
	printf("\n");
	return 0;
}
