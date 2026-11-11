#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]=i;
	}
	for(long long i=1;i<=n;i++){
		long long j=i;
		while(j<=n){
			j=cnt[a[j]];
			ans[a[j]]++;
			j++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
