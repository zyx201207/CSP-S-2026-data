#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans[1005]= {},f[1005]= {},a[1005]= {},s[1005]= {},cnt=1;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int sz=n-i+1;
		while(sz>=0) {
			if(f[a[i]]==0) {
				f[a[i]]++;
				s[cnt++]=a[i];
				sz--;
			} else {
				for(int j=1; j<=n; j++) {
					if(s[j]==a[i]) {
						for(int x=j+1; x<=cnt; x++) {
							s[x]=0;
							f[a[x]]=0;
						}
						break;
					}
				}
				f[a[i]]=1;
				sz--;
			}
		}
		for(int i=1; i<=n; i++) {
			if(f[i]==1) {
				ans[i]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
