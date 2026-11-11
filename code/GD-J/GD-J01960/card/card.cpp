#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500009];
int r[500009];
int cnt[500009];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	for(int i = n;i>=1;--i){
		if(r[a[i]] == 0) r[a[i]] = i;
	}
	for(int i = 1;i<=n;++i){
		int pos = i;
		while(pos<=n){
			cnt[a[pos]]++;
			pos = r[a[pos]]+1;
		}
	}
	for(int i = 1;i<=m;++i){
		cout<<cnt[i]<<" ";
	}
}
