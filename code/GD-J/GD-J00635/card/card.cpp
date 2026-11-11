#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt[300005],b[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<i;j++){
			cnt[a[j]]++;
		}
		for(int j=i+1;j<=n;j++){
			if(cnt[a[j]]!=0){
				b[i]+=1;
			}
		}
	}
	b[a[n]]=n;
	for(int i=1;i<=n;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
