#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010],v[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		v[a[i]]=i;
		for(int j=i+1;j<=n;j++){
			if(v[a[j]]==0){
				v[a[j]]=j;
				continue;
			}
			for(int k=1;k<=m;k++){
				if(v[k]>v[a[j]] && v[k]<j) v[k]=0;
			}
			v[a[j]]=j;
		}
		for(int k=1;k<=m;k++){
			if(v[k]) ans[k]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
