#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a[100],b[100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&b[j]);
		}
	}
	return 0;
} 
