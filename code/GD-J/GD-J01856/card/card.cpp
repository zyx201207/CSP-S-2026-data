#include <bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],tb[300005],ea[300005];
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		int di=j;
		for(int i=1;i<=m;i++) ea[i]=-1;
		for(int i=j;i<=n;i++){
			if(ea[a[i]]!=-1){
				for(int o=di;o>ea[a[i]];o--) tb[o]=0;
				di=ea[a[i]]+1;
			}
			else{
				ea[a[i]]=di;
				tb[di]=a[i];
				di++;
			}
		}
		for(int i=j;i<=n;i++){
			cout<<tb[i]<<endl;
			if(tb[i]!=0) ans[tb[i]]++;
			else break;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
