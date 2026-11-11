#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		if(a[i]!=a[i+1]) printf("%d ",i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
