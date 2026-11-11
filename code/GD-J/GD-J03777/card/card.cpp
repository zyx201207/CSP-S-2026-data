#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int n,m,a[MAXN],e[MAXM],l[MAXM],b[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=i;
		l[a[i]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",i);
	return 0;
}
