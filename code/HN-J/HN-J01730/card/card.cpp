#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
bool is[300005];
int ans[300005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int t = 1;t <= n;t++) {
		stack<int> s;
		memset(is,false,sizeof(is));
		for(int i = t;i <= n;i++) {
			if(is[a[i]]) {
				while(!s.empty() && s.top() != a[i]) is[s.top()] = false,s.pop();
				s.pop();
				s.push(a[i]);
			}
			else {
				s.push(a[i]);
				is[a[i]] = true;
			}
		}
		for(int i = 1;i <= m;i++) if(is[i]) ans[i]++;
	}
	for(int i = 1;i <= m;i++) printf("%d ",ans[i]);
	return 0;
}
