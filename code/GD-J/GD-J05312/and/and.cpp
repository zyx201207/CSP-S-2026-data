#include<bits/stdc++.h>
int n,m,a[200005],r;
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++) std::cin>>a[i];
	std::sort(a+1,a+n+1,[](int p,int q){return p>q;});
	r=a[1];
	for(int i=2;i<=m;i++) r&=a[i];
	std::cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
