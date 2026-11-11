#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,a[N],ans[N],cnt[N];
bool vis[N];
deque<int> q[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				q[i].push_back(a[j]);
				vis[a[j]]=1;
				cnt[a[j]++];
			}else{
				for(int k=0;k<q[i].size();k++){
					bool ok=0;
					if(q[i][k]==a[j]&&!ok){
						for(int l=1;l<=q[i].size()-k;l++){
							q[i].pop_back();
							if(cnt[a[l]]==1){
								vis[a[l]]=0;
								cnt[a[l]]--;
							}else{
								cnt[a[l]]--;
							}
						}
						ok=1;
					}
				}
				q[i].push_back(a[j]);
				cnt[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<q[i].size();k++){
				if(q[i][k]==j) ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
