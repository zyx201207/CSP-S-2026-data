#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],b[3010];
bool c[3010],c1[5010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int u=n,k=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n--){
		for(int i=k;i<=u;i++){
			c1[i]=1;
			if(c[a[i]]==1){
				int y=i-1;
				c1[i]=0;
				while((a[i]!=a[y]||c1[y]==0)&&y!=0){
					c1[y]=0;
					y--;
				}
			}
			else {
				c[a[i]]=1;
			}
		}
		for(int i=k;i<=u;i++){
			if(c1[i]==1){
				b[a[i]]++;
			}
			c1[i]=0;
			c[a[i]]=0;
		}
		k++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}

