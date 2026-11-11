#include <bits/stdc++.h>
#include <climits>
int n,m,a[200010],ans,am=INT_MAX;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
		std::cin>>a[i];
	int sz=n;
	for(int ls=30;ls>=0;ls--) {
		ans<<=1;
		for(int i=1;i<=sz;i++) a[i]&=am;
		std::sort(a+1,a+1+sz,std::greater<int>());
		int lp=0;
		while((a[lp+1]>>ls)&&lp<=sz) lp++;
		if(lp>=m) {
			ans+=1;
			sz=lp;
		}
		am>>=1;
	}
	std::cout<<ans;
	return 0;
}
