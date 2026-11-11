#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=m;m>=1;i--)printf("%d",&i);
	return 0;
}
