#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005],ans[300005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]+=1;
		cnt[a[i]]=i;
	}
	for(int j=0;j<n;j++){
		num[a[j]]--;
		if(j==cnt[a[j]]){
			num[a[j]]=0,cnt[a[j]]=0;
		}
		for(int i=j+1;i<=n;i++){
			ans[a[i]]++;
			if(num[a[i]]>=2&&i<cnt[a[i]]){
				i=cnt[a[i]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//May all the beauty be blessed.
