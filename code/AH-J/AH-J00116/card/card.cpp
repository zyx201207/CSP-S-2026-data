#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],b[10005];
int cnt[300005];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n>500){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]!=a[j-1]){
					sum++;
				}
			} 
		}
		cout<<sum;
		return 0;
	}
	for(int ju=1; ju<=n; ju++) {
		int now=1;
		memset(b,0,sizeof b);
		for(int i=ju; i<=n; i++,now++) {
			for(int j=1; j<now; j++) {
				if(b[j]==a[i]) {
					now=j;
					break;
				}
			}
			b[now]=a[i];
		}
		for(int k=1;k<now;k++){
			cnt[b[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

