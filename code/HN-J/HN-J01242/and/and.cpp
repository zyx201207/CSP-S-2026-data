#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,arr[200005],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=31;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(((arr[j]>>i)&1)==1){
				cnt++;
			}
		}
		if(cnt<m){
			continue;
		}
		ans+=1<<i;
		for(int j=1;j<=n;j++){
			if(((arr[j]>>i)&1)==0){
				arr[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
