#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[500005];
int t[500005];
int b[300005];
int ans[300005];
bool temp[500005];
int asd2[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>v[i];
	}
	for(int i=n; i>=1; i--) {
		if(asd2[v[i]]!=0) {
			b[i]=asd2[v[i]];
		}
		asd2[v[i]]=i;
	}
	for(int j=1; j<=n; j++) {
		memset(temp,0,sizeof(temp));
		for(int i=j; i<=n; i++) {
			if(b[i]!=0) {
				if(temp[v[i]]==0) {
					ans[v[i]]++;
				}
				temp[v[i]]=1;
				i=b[i]-1;
			} else {
				if(temp[v[i]]==0) {
					ans[v[i]]++;
				}
				temp[v[i]]=1;
				ans[v[i]]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]/2<<" ";
	}
}
