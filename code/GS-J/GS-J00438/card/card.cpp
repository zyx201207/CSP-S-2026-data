#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
bool b[maxn];
int ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;++i){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;++j){
			if(b[a[j]]==1){
				int len=1;
				while(a[j-len]!=a[j]&&j-len>i){
					b[a[j-len]]=0;
					len++;
				}
			}else{
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=m;++j){
			if(b[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}
/*10 3
3 1 2 1 3 2 3 1 2 1*/

