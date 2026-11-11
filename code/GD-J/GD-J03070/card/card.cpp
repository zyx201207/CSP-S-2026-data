#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,pos;
int a[N],maxpos[M],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxpos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(maxpos[a[j]])
				j=maxpos[a[j]];
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",cnt[i]);
	return 0;
}
