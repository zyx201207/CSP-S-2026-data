#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200007];
int last[200007];
map<int,int> ans;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans[a[i]]++;
	}
	int now=0;
	for(auto y : ans){
		now=now+y.second;
		printf("%d ",now);
	}
	return 0;
}
