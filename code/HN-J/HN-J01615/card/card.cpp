#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int n,m;
int a[N];
int T[N];
int lst[N];
int nxt[N];
int now[N];
int ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(now[a[i]]){
			nxt[i]=now[a[i]];
		}
		now[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<'\n';
		for(int j=i;j<=n;j++){
			while(nxt[j]){
				j=nxt[j];
			}
//			cout<<j<<' ';
			ans[a[j]]++;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m)cout<<' ';
	}
	cout<<'\n';
	return 0;
}
