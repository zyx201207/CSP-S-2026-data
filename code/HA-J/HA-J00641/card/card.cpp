#include <bits/stdc++.h>
using namespace std;
int n,a[500005];
int m;
int b[500005],t[500005];
int ans[500005];
int sum[500005];
void ones (int v) {
	for (int i = 1;i <= m;i ++) sum[i] = 0;
	for (int i = v;i <= n;i ++) {
		sum[a[i]] ++;
		if (sum[a[i]] >= 2) {
			int j = i - 1;
			while (a[j] != a[i]) {
				sum[a[j --]] --;
//				cout<<"*"<<j<<" ";
			}
//			cout<<"\n"; 
			sum[a[j]] --;
		}
	}
	for (int i = 1;i <= m;i ++) {
		ans[i] += int(sum[i]>0);
//		cout<<v<<":"<<i<<" "<<sum[i]<<"\n";
	}
}
int main () {
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++) {
		cin>>a[i];
	}
	for (int i = 1;i <= n;i ++) {
		ones(i);
	}
	for (int i = 1;i <= m;i ++) {
		cout<<ans[i]<<" "; 
	}
	fclose (stdin);
	fclose (stdout);
	return 0;	
}
