#include<bits/stdc++.h>
using namespace std;
int a[1000000],f[500010];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= m;i++) f[i] = 1;
	for(int i = 1;i <= n;i++){
		f[a[i]] = max(f[a[i]],i);
	}
	for(int i = 1;i <= m;i++) cout<<f[i]<<" ";
	
	return 0;
}
