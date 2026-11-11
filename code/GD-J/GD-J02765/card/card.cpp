#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[300010],h[300010],w[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int z=1;z<=n;z++){
		for(int i=1;i<=n;i++){
			h[a[i]]=false;
			w[i]=0;
		}
		int t=z-1;
		for(int i=z;i<=n;i++){
			if(h[a[i]]==false){
				h[a[i]]=true;
				t++;
				w[t]=a[i];
			}
			else{
				int k;
				for(int j=z;j<=m;j++){
					if(a[j]==a[i]){
						k=j;
						break;
					}
				}
				for(int j=k;j<=i;j++){
					h[a[j]]=false;
					w[j]=0;
				}
				t=k;
				w[t]=a[i];
				h[a[i]]=true;
			}
		}	
		for(int j=1;j<=m;j++){
			if(h[j]==true) s[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	return 0;
}
