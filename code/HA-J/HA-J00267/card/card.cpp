#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int cnt[maxn];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		cnt[a[i]]++;
	}
	for(int i=1; i<=m; i++){
		cout<<cnt[i]<<" ";
	} 
	return 0;
}
