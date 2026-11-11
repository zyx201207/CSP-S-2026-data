#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,a1,t1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	vector<int>w(m+1);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	vector<int>a(n+1),t(n+1),x(n),y(n);
	for(int i=1;i<=n;i++){
		int s;
		while(s--){
			scanf("%d%d",&a[++a1],&t[++t1]);
		}
	}
	while(q--){
		int x,y,sum;
		scanf("%d%d",&x,&y);
		sum+=w[x];
		for(int i=x;i<=y;i++)
			sum+=t[i]+w[i];
		printf("%lld",sum);
		}
	return 0;
	
}
