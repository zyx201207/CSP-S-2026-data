#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int tong[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(b[j]==b[l]){
					for(int k=j;k<l;k++){
						b[k]=0;
					}
				}
			}
		}
		/*for(int j=1;j<=n;j++){
			printf("b[%d]=%d ",j,b[j]);
		}
		cout<<endl;*/
		for(int j=i;j<=n;j++){
			if(b[j])tong[b[j]]++;
		}
		/*for(int j=1;j<=m;j++)printf("tong[%d]=%d",j,tong[j]);
		cout<<endl;*/
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
