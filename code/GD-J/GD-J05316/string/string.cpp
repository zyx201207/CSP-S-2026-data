#include <bits/stdc++.h>
struct c{
	int s=0;
	char x;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	long long ans=0;
	c m[200005];
	std::cin>>n;
	for(int i=1;i<=n;i++)std::cin>>m[i].s>>m[i].x;
	int l=1,r=n;
	while(l<r){
		if(m[l].x!=m[r].x)ans+=std::min(m[l].s,m[r].s);
		if(m[l].s<m[r].s)m[r].s-=m[l].s,l++;
		else if(m[l].s>m[r].s)m[l].s-=m[r].s,r--;
		else l++,r--;
	}
	std::cout<<ans;
	return 0;
}
