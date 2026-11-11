#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int n,m,a[500005],ans[300005],vis[300005],last[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    if(m==2&&n>5) {
		if(a[n]==1) cout<<n<<' ';
		else if(a[n-1]==1) cout<<n-1<<' ';
		else cout<<0<<' ';
		if(a[n]==2) cout<<n<<' ';
		else if(a[n-1]==2) cout<<n-1<<' ';
		else cout<<0<<' ';
		return 0;
	}
    for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++) {
			if(vis[a[j]]) {
				for(int k=last[a[j]];k<=j;k++) {
					vis[a[k]]=0;
				}
			}
			vis[a[j]]=1,last[a[j]]=j;
		}
		for(int j=1;j<=m;j++) {
			if(vis[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) {
		printf("%d ",ans[i]);
	}
    return 0;
}
