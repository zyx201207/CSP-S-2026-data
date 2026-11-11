#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[600005],cnt[600005],top=0,vis[500005],zzqs[600005],o[500005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
		vis[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			if(j<vis[a[j]])  j=vis[a[j]];
			zzqs[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<zzqs[i]<<" ";
	}
	return 0;
}
