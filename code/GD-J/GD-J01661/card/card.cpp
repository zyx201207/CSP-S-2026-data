#include<bits/stdc++.h>
using namespace std;
int b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		b[a]=i;
	}
	for(int i=1;i<=m-1;i++){
		printf("%d ",b[i]);
	}
	printf("%d",b[m]);
	return 0; 
} 
