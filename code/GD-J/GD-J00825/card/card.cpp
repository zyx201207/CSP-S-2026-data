#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int nxt[M];
ll cnt[N];
ll ans[M];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		nxt[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cnt[i]++;
//		cout<<i<<" "<<cnt[i]<<"\n";
		if(i>1 && nxt[a[i-1]]==i-1){
			cnt[i]+=cnt[i-1];
		}
//		cout<<i<<" "<<cnt[i]<<"\n";
		if(nxt[a[i]]==i){
			ans[a[i]]=cnt[i];
		}
		else{
			cnt[nxt[a[i]]]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m){
			cout<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
