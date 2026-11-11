#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int cnt[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1])cnt[a[i-1]]++;
	}cout<<1;
	for(int i=1;i<m;i++)cout<<cnt[i];
	return 0;
}