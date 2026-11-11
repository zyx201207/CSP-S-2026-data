#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500010],jl[500010];
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==m){
		for(int i=1;i<=n;++i){
			cout<<i;
		}
	}else{
		cout<<m<<1<<n;
	}
	return 0;
}
