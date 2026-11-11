#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,m,a[N],pre[N],pos[N],ans[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pos[a[i]],pos[a[i]]=i;
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++){
			if(pre[j]>=i){
				for(int k=pre[j];k<j;k++)
					if(cnt[a[k]])
						cnt[a[k]]--;
			}
			cnt[a[j]]++;
		}
		for(int j=1;j<=m;j++)
			if(cnt[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

