#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
bool b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				memset(b,0,sizeof(b));
			}
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1){
				t[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",t[i]);
	}
	return 0;
}
