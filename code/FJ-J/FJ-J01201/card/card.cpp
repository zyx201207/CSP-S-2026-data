#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],nex[500005];
long long ans[300005],t[300005],pre[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(t[a[i]]!=0){
			nex[pre[a[i]]]=i;
		}
		pre[a[i]]=i;
		t[a[i]]++;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			ans[a[j]]++;
			while(nex[j]!=0){
				j=nex[j];
			}
		}
	}
	for(long long i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
