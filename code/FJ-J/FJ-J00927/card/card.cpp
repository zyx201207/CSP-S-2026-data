#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000010],rmax[1000010],cnt[1000010];
bool flag=1;
void pianfen(){
	for(ll i=1;i<=m;i++) cout<<rmax[i]<<' ';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		rmax[a[i]]=i;
		if(a[i-1]>a[i]) flag=0;
	}
	if(flag){
		pianfen();
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ll l=i;
		while(l<=n){
			cnt[a[l]]++;
			if(rmax[a[l]]!=l) l=rmax[a[l]]+1;
			else l++;
		}
	}
	for(ll i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
