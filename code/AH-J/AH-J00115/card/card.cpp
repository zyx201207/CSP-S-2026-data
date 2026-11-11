#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],c[N],b[N],pre[N];
bool f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int h=0,t=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			if(i==1&&j==1){
				b[++h]=a[j];
				t++;
				f[a[j]]=true;
				if(pre[a[j]]==0){
					pre[a[j]]=j;
				}
				continue;
			}
			if(f[a[j]]==false){
				b[++t]=a[j];
				f[a[j]]=true;
				if(pre[a[j]]==0){
					pre[a[j]]=j;
				}
			}else{
				int m2=t;
				t=pre[a[j]];
				for(int k=t+1;k<=m2;k++){
					f[a[k]]=false;
					pre[a[k]]=0;
				}
				for(int k=1;k<=t;k++){
					if(b[k]==a[j]){
						t--;
						for(int s=k;s<=m2;s++){
							b[s]=b[s+1];
							pre[b[s]]=pre[b[s+1]];
						}
					}
				}
				f[a[j]]=true;
				b[++t]=a[j];
				pre[a[j]]=t;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[a[j]]==true){
				c[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",c[a[i]]);
	}
	return 0;
}
