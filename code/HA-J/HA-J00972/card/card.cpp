#include <bits/stdc++.h>
using namespace std;
long long n,m,a[300010];
map<long long,long long> p,ans;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<=n;j++) {
			p[a[j]]++;
			if (p[a[j]]==2) {
				long long wz=0;
				for (int k=i+1;k<=n;k++) {
					if (a[k]==a[j]) {
						wz=k;
						break;
					}
				}
				//cout<<i<<" "<<wz<<' '<<j<<endl;
				for (int k=wz;k<=j;k++) {
					p[a[k]]=0;
				}
				p[a[j]]=1;
			}
		}
		for (int j=1;j<=n;j++) {
			if (p[a[j]]!=0) {
				ans[a[j]]++;
			}
			p[a[j]]=0;
		}
	}
	for (int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
