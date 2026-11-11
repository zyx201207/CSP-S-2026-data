#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll cnt[N],a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll k=1;k<=n;k++){
		memset(cnt,0,sizeof cnt);
		for(ll i=k;i<=n;i++){
			cnt[a[i]]++;
			if(cnt[a[i]]==2){
				int flag=a[i];
				for(ll j=i-1;;j--){
					if(a[j]==flag) break;
					if(cnt[a[j]]!=0)cnt[a[j]]--;
				}
				cnt[a[i]]--;
			}
		}
		for(ll i=1;i<=m;i++){
			ans[i]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
