#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n,m,a[1000],ans[1000],table[1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans[a[n]]++;
	if (a[n]!=a[n-1]){
		ans[a[n]]++;
		ans[a[n-1]]++;
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
