#include<bits/stdc++.h>
using namespace std;
int s[100100],id;
int n,m,a[200010],num[100100];
bool vis[100100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card".out,"w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		
	}
	for(int j=1;j<=n;++j){
		for(int i=j;i<=n;++i){
			if(vis[a[i]]==0){
				id++;
				s[id]=a[i];
			}else{
				while(s[id]!=a[i]){
					vis[s[id]]=0;
					id--;
				}
			}
		}
		while(id>0){
			num[s[id]]++;
			id--;
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d ",num[i]);
	}
	return 0;
}
