#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,a[N],ans[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		int b[n],c=1;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==1)
				for(int k=c-1;k>0;k--){
					cnt[b[k]]=0;
					if(a[j]==b[k]){
						c=k;
						break;
					}
				}
			cnt[a[j]]=1;
			b[c]=a[j];
			c++;
		}
		for(int j=1;j<c;j++) ans[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
