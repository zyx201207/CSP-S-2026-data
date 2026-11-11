#include<bits/stdc++.h>
using namespace std;
int a[500010],p[500010],ans,n,m,sum[500010];
bool f[500010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		ans=0;
		for(int j=i; j<=n; j++) {
			ans++;
			if(!f[a[j]]) {
				f[a[j]]=true;
				p[a[j]]=ans;
			} else {
				ans=p[a[j]];
				for(int k=1; k<=m; k++) {
					if(f[k]&&p[k]>p[a[j]]) {
						f[k]=false;
						p[k]=0;
					}
				}
			}
		}
		for(int j=1; j<=m; j++) {
			if(f[j]) {
				f[j]=false;
				p[j]=0;
				sum[j]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<sum[i]<<" ";
	}
	return 0;
}
