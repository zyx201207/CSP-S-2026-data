#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],t[N],st[N],t1[N],cnt[N];//t1 s t b
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1) {
		cout<<n;
		return 0;
	} else if(m==2) {
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			if(a[i]==1&&a[n]==1) {
				cnt[1]++;
			} else if(a[i]==2&&a[n]==2) {
				cnt[2]++;
			} else {
				cnt[1]++;
				cnt[2]++;
			}
		}
		for(int i=1; i<=m; i++) {
			cout<<cnt[i]<<' ';
		}
		return 0;
	}else{
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]){
				cnt[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
	}

	return 0;
}
