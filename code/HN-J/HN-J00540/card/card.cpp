#include<bits/stdc++.h>
using namespace std;

int n,m,cnt_table;
int cards[500010],table[500010];
int ans[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&cards[i]);
	}
	for(int i=1;i<=n;i++){
		memset(table,0,sizeof table);
		cnt_table=0;
		for(int j=i;j<=n;j++){
			if(find(table,table+cnt_table,cards[j])-table==cnt_table){
				table[++cnt_table]=cards[j];
			}
			else{
				cnt_table=find(table,table+cnt_table,cards[j])-table;
			}
		}
		for(int j=1;j<=cnt_table;j++){
			ans[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

