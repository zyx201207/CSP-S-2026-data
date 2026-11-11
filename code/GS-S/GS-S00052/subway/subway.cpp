#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
long long ti=0;
int a[500010]={},k[510]={};
int num[500][500010];
int tin[2][1];
int start[100010]={},end[100010]={};



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int l=1;l<=k[i];l++){
			scanf("%d%d",&num[k[i]][i],&tin[2][1]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&start[i],&end[i]);
	}
	for(int i=1;i<=q;i++){
		
		
		printf("%lld\n",ti);
	}
	return 0;
}
//ti+=(q-1)*(2*tin[2][1]);
//ti=(a[start[i]])+(a[end[i]]);
