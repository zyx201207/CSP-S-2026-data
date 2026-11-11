#include <bits/stdc++.h>
using namespace std;
const int maxm=3e5+5;
const int maxn=5e5+5;
int sr[maxm];
int zr[maxn];
int a[maxn];
int ans[maxm];
int st[maxm];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		zr[sr[a[i]]]=i;
		sr[a[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(st[a[j]]!=i) {
				ans[a[j]]++;
				st[a[j]]=i;
			}
			while(zr[j]!=0) {
				j=zr[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
