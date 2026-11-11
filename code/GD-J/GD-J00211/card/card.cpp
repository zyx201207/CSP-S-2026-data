#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
int a[MAXN];
int cnt[MAXN];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i = 1;i<=n;i++) cout<<a[n]<<' ';
	return 0;
}
