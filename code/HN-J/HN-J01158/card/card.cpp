#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],ans[500001],st[500001],r=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		r=0;
		for(int j=i;j<=n;j++){
			st[++r]=a[j];
			for(int k=r-1;k>=1;k--){
				if(st[r]==st[k]){
					r=k;
				}
			}
		}
		for(int i=1;i<=r;i++){
//			cout<<st[i]<<" ";
			ans[st[i]]++;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
