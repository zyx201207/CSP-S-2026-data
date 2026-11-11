#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
vector<int> sub(500005);
int w[500005],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		ans=max(w[i],ans);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int a,t;
			scanf("%d %d",&a,&t);
		}
		int y,u;
		cin>>y>>u;
		printf("%d",ans);
	}
	return 0;
}
