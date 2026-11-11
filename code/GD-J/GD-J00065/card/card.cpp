#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5005],nb[5005],cnt[5005],vis[5005],ans;
bool f;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(vis[j]==0){
					cnt[j]++;
					vis[j]=1;
				}
				if(a[j]!=a[j-1]){
					vis[j-1]=0;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}		
		//cout<<"\n";
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;){
			cnt[a[i]]++;
			int l=i;
			for(int j=n;j>=i;j--){
				if(a[j]==a[i]){
					l=j;
					break;
				}
			}
			//cout<<l<<" ";
			l++;
			//cout<<l<<" ";
			i=l;
		}
//		for(int i=1;i<=m;i++){
//			cout<<cnt[i]<<" ";
//		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
