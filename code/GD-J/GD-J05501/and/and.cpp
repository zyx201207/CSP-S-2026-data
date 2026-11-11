#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,res=0b1111111111111111111111111111111;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		mp[t]++;
	}
	auto p=mp.end();
	while(m>0){
		p--;
		m-=p->second;
		res&=p->first;
	}
	cout<<res;
	return 0;
}

