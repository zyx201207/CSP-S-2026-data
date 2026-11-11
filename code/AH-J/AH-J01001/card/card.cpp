#include <bits/stdc++.h>
using namespace std;
	int n, m,mx=-1e9;
	int x;
	int cnt[500010];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	while(n--){
		cin>>x;
		cnt[x]+=1;
		mx=max(mx,x);
	}
	for(int i=1;i<=mx;i++){
		if(cnt[i]>=0)
			cout<<cnt[i]<<" ";
	}
	return 0;
}
