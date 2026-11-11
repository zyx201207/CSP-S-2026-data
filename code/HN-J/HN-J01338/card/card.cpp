#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int card[500005];
long long ans[300005];
int las[300005];
int mapp[300005];
int cnt;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(ans,0,sizeof ans);
	for(int i=1;i<=n;i++) cin>>card[i];
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(las,0,sizeof las);
		for(int j=i;j<=n;j++){
			cnt++;
			if(las[card[j]]!=0&&las[card[j]]<cnt)
				cnt=las[card[j]];
			mapp[cnt]=card[j];
			las[card[j]]=cnt;
		}
		for(int j=1;j<=cnt;j++){
			ans[mapp[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
