//GZ-J00600 贵阳华师一学校 蒋金珂
#include<bits/stdc++.h>
using namespace std;
int a[500001],ans[500001];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool op=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]<a[i-1])op=0;
	}
	if(op) {
		for(int i=1; i<=n; i++) {
			ans[a[i]]=i;
		}
		for(int i=1; i<=m; i++) {
			cout<<ans[i]<<" ";
		}
	} else {
		for(int lun=1; lun<=n; lun++) {
			map<int,int>mp;
			for(int i=lun; i<=n; i++) {
				if(mp[a[i]]) {
					for(int j=1; j<=m; j++) {
						if(mp[a[i]]<mp[j]) {
							mp[j]=0;
						}
					}
				}
				mp[a[i]]=i;
			}
			for(int i=1; i<=m; i++) {
				if(mp[i])ans[i]++;
			}
		}
		for(int i=1; i<=m; i++) {
			cout<<ans[i]<<" ";
		}

	}

}

