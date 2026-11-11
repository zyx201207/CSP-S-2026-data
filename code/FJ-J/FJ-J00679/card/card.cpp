#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=n;j>=1;j--){
		if(!b[a[j]]){
			b[a[j]]=j;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		cnt[a[j]]++;
		while(j<n){
			j=b[a[j]];
			if(j<n){
				j++;
				cnt[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
