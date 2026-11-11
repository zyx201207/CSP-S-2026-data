#include<bits/stdc++.h>
using namespace std;
int n,m,a[514514],zhuo[314514],head,zhan[514514],tou[314514];
int ans[514514];
void init(){
	memset(zhuo,0,sizeof(zhuo));
	memset(zhan,0,sizeof(zhan));
	memset(tou,0,sizeof(zhan));
	head=0;
}
void baoli(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		init();
		for(int j=i;j<=n;j++){
			if(!zhuo[a[j]]){
			zhuo[a[j]]=1;
			zhan[++head]=a[j];
			tou[a[j]]=head;
			}else{
				for(int k=tou[a[j]]+1;k<=head;k++){
				tou[a[j]]=0;
				zhuo[zhan[k]]=0;
				}
				head=tou[a[j]];
			}
		}for(int j=1;j<=m;j++){
			if(zhuo[j])ans[j]++;
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	cout<<'\n';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	baoli();
	return 0;
}
