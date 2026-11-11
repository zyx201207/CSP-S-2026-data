#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[50100],t[30100][2],cnt[30100];
signed main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			t[a[j]][0]++;
			if (t[a[j]][0]==2) {
				for (int k=t[a[j]][1];k<=j;k++) {
					t[a[k]][0]=0;
					t[a[k]][1]=0;
				}
				t[a[j]][0]++;
			}
			t[a[j]][1]=j;
		}
		for (int j=1;j<=m;j++) {
			if (t[j][0]!=0) {
				cnt[j]++;
				t[j][0]=0,t[j][1]=0;
			}
		}
	} 
	for (int i=1;i<=m;i++) {
		cout<<cnt[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
