#include <bits/stdc++.h>
int n,m,a[500010],t[300010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++) {
		std::cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=m;i++) t[m]=(t[m]*(t[m]-1))/2;
	t[a[n]]=n;
	for(int i=1;i<=m;i++) {
		std::cout<<t[i]<<' ';
	}
	return 0;
}
