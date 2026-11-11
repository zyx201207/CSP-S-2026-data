#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
using namespace std;
int n,m;
int a[500010];
int iff[500010];
int nxt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	io;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cout<<n-1<<' ';
	}
	return 0;
}
