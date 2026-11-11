#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,b[500005],f[300005],y[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int u=1;u<=n;u++){
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		for(int i=u;i<=n;i++){
			int cnt=0;
			b[cnt++]=a[i];
			if(f[a[i]]==1){
				for(int j=cnt-1;j>=1;j--){
					f[b[j]]=0;
					b[j]=0;
					if(b[j]==a[i]){
						f[b[j]]=0;
						b[j]=0;
						break;
					}
				}
			}
			f[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(f[i]==1){
				y[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",y[i]);
	}
	
}
