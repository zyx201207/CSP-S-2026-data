#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],id[M],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int s=i;
		while(s<=n){
			cnt[a[s]]++;
			s=id[a[s]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
