#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
bool f[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]) ans[a[i-1]]=i-1;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}