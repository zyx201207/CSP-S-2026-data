#include<bits/stdc++.h>
using namespace std;
int s[500010],e[500010];
bool f[300010];
stack<int> vis;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
	}
	if (n<=5000) {	
		for (int i=1;i<=n;i++) {
			for (int j=i;j<=n;j++) {
				if (f[s[j]]==0) {
					vis.push(s[j]);
					f[s[j]]=1;
				} else {
					int ll=vis.size();
					for (int z=1;z<=ll;z++) {
						if (vis.top()==s[j]) {
							break;
						} else {
							f[vis.top()]=0;
							vis.pop();
						}
					}
				}
			}
			int l=vis.size();
			for (int j=1;j<=l;j++) {
				e[vis.top()]++;
				f[vis.top()]=0;
				vis.pop();
			}
		}
		for (int i=1;i<=m;i++) {
			cout<<e[i]<<" ";
		}
	} else {
		for (int i=1;i<=n;i++) {
			for (int j=i;j<=n;j++) {
				if (f[s[i]]==0) {
					vis.push(s[i]);
					f[s[i]]=1;
				}
			}
			int l=vis.size();
			for (int i=1;i<=l;i++) {
				e[vis.top()]++;
				f[vis.top()]=0;
				vis.pop();
			}
		}
		for (int i=1;i<=n;i++) {
			cout<<e[i]<<" ";
		}
	}
	return 0;
}
