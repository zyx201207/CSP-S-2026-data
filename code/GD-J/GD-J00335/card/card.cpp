#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt[300005];
		int mp[500005];
		for(int j=1;j<=n;j++){
			mp[j]=0;
		}
		for(int j=1;j<=m;j++){
			cnt[j]=0;
		}
		int c=1;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				cnt[a[j]]=j;
				mp[j]=a[j];
			}else{
				for(int k=cnt[a[j]]-1;k<j;k++){
					mp[k]=0;
				}
				mp[j]=a[j];
				cnt[a[j]]=0;
			}
		}
		for(int j=1;j<=n;j++){
			sum[mp[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
