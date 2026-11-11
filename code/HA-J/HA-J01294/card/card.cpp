#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],k,t[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++) {
		int num=0,b[100005];
		for(int i=1; i<=n; i++) {
			if(i<k)continue;
			else {
				bool f=0;
				for(int j=0; j<num; j++) {
					if(f==1) {
						b[j]=-1;
					} else if(b[j]==a[i]) {
						b[j]=-1;
						f=1;
					}
				}
				b[num]=a[i];
				num++;
			}
		}
		for(int j=0; j<num; j++)t[b[j]]++;
	}
	for(int j=1; j<=m; j++)if(t[j])cout<<t[j]<<" ";
	return 0;
}
