#include <bits/stdc++.h>
using namespace std;
int n,m,a[300005],ans[300005];
bool t[300005];
stack<int>s;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		memset(t,0,sizeof(t));
		for(int j=i; j<=n; j++) {
			if(t[a[j]]==1) {
				while(s.top()!= a[j]) {
					t[s.top()]=0;
					s.pop();
				}
			} else {
				s.push(a[j]);
				t[a[j]]=1;
			}
		}
		while(!s.empty()) {
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1; i<=m; i++)
		printf("%d ",ans[i]);
	return 0;
}

