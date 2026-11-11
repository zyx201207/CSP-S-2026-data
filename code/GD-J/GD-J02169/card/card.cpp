#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	vector<int> v(n+1,0);
	vector<int> ans(m+1,0);
	for(int i=1; i<=n; i++) {
		scanf("%d",&v[i]);
	}
	for(int i=1; i<=n; i++) {
		stack<pair<int,int>> t;
		vector<int> a(m+1,0);
		for(int j=i; j<=n; j++) {
			if(a[v[j]]==0) {
				t.push(make_pair(v[j],j));
				a[v[j]]=j;
			}
			else {
				while(!t.empty()&&t.top().first!=v[j]) {
					if(t.top().second==a[t.top().first]) {
						a[t.top().first]=0;
					}
					t.pop();
				}
				if(!t.empty()) {
					if(t.top().second==a[v[j]]) {
						a[v[j]]=0;
					}
					t.pop();
				}
				if(a[v[j]]==0) {
					a[v[j]]=j;
				}
				t.push(make_pair(v[j],j));
			}
		}
		for(int j=1; j<=m; j++) {
			a[j]=0;
		}
		while(!t.empty()) {
			if(a[t.top().first]==0) {
				ans[t.top().first]++;
				a[t.top().first]=1;
			}
			t.pop();
		}
	}
	for(int i=1; i<=m; i++) {
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
