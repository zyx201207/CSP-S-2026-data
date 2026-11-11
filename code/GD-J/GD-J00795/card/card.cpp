#include<bits/stdc++.h>
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=3e5+10;
void _freopen(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
int cnt[N];
int a[N];
int ans[N];
int pos[N];
void solve(){
	int x=0;
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
		if(cnt[a[i]]==1) pos[a[i]]=i;
		if(cnt[a[i]]>1) x=i;
		ans[a[i]]+=i;
	}
	for(int i=1;i<=pos[a[x]];i++){
		ans[a[i]]-=i;
	}
	for(int i=pos[a[x]];i<x;i++){
		ans[a[i]]-=i-pos[a[x]];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';	
} 
signed main(){
	No TLE
	_freopen();
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
}

