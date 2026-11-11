#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int a[N],cnt[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]%2==1) ans[i]++;
		}
		memset(cnt,0,sizeof(cnt));
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}