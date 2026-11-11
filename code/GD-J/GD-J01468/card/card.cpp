#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m,a[500005],flag[500005],cnt[500005],v[500005],k[500005],va[500005],s;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--) {
		if(k[a[i]]) v[i]=k[a[i]];
		k[a[i]]=i;
	}
	for(int i=1;i<=m;i++) k[i]=0;
	for(int i=1;i<=n;i++) {
		s=i;
		for(;s<=n;) {
			if(v[s]) s=v[s];
			else va[a[s]]++,s++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",va[i]);
	return 0;
}
