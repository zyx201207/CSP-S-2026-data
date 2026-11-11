#include<bits/stdc++.h>
using namespace std;
int n,m,a[1111111];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<i;
	}
	return 0;
} 
