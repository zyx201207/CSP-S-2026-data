#include<bits/stdc++.h> 
using namespace std;
struct cards{
	int l,s;
}cnt[6000001][6000001];
int n,m,a[6000001],ans[6000006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(cnt[a[j]][i].s==0){
				cnt[a[j]][i].l=j;
				cnt[a[j]][i].s++;
			}else{
				for(int k=cnt[a[j]][i].l;k<=j;k++)
					cnt[a[k]][i].s--;
			}
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			ans[i]+=cnt[i][j].s;
	for(int i=1;i<=n;i++)
		printf("%d",ans[i]);
	return 0;
}
