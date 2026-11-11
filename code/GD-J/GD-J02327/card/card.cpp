#include <bits/stdc++.h>

int a[500001];
int s[500001];

int main(){
	std::freopen("card.in","r",stdin);
	std::freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	int n,m;
	std::cin>>n>>m;
	for (int i=1;i<=n;i++) std::cin>>a[i];
	for (int i=1;i<=n;i++){
		bool b[300001]={false};
		std::vector<int> c;
		for (int j=i;j<=n;j++){
			if (b[a[j]]){
				while (c.back()!=a[j]){
					b[c.back()]=false;
					c.pop_back();
				}
				c.pop_back();
			}
			b[a[j]]=true;
			c.push_back(a[j]);
		}
		for (int j:c) s[j]++;
	}
	for (int i=1;i<=m;i++) std::cout<<s[i]<<(i<m?" ":"");
	return 0;
}

