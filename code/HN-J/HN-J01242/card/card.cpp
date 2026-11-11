#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,arr[500005],sum[500005],ans[500005],lst[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		lst[arr[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int inx=i;
		while(1){
			ans[arr[inx]]++;
			inx=lst[arr[inx]]+1;
			if(inx>n){
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//388pts
