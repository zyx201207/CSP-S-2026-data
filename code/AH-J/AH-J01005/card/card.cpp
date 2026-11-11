#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
ll cnt[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		vector<ll> v;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==1){
				cnt[a[j]]=0;
				while(v[v.size()-1]!=a[j]&&(!v.empty())){
					cnt[v[v.size()-1]]--;
					
					v.pop_back();
				}
				if(!v.empty())v.pop_back();
				
				
			}
			v.push_back(a[j]);
			cnt[a[j]]++;
		}
		for(int j=1;j<=m;j++) ans[j]+=cnt[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
