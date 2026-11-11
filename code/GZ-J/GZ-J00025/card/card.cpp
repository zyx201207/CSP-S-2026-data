//GZ-J00025 贵阳市白云区华师一学校 吴星汉 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],cnt[500010],l[500010];
vector<ll> id[500010];
bool f[500010],vis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;n>=i;i++){
		scanf("%lld",&a[i]);
		id[a[i]].push_back(i);
	}
	for(ll i=1;n>=i;i++){
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		for(ll j=1;m>=j;j++){
			if(id[j].size()-l[a[i]]==1 || id[j].size()-l[a[i]]==0) continue;
			for(ll k=l[j];id[j].size()>k;k+=2){
				for(ll p=id[j][k]+1;id[j][k+1]>=p;p++){
					f[p]=1;
				}
			}
		}
		l[a[i]]++;
		for(ll j=i;n>=j;j++){
			if(f[j]==0 and vis[a[j]]==0){
				cnt[a[j]]++;
				vis[a[j]]=1;
			}
		}
	}
	for(ll i=1;m>=i;i++) printf("%lld ",cnt[i]);
	return 0;
}
