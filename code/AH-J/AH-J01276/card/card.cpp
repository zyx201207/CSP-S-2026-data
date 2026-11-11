#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],wz[300010],f[300010],ans[300010];
bool pd=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) pd=false;
	}
	if(pd){
		for(int i=n;i>=1;i--)
			ans[a[i]]=max(ans[a[i]],i);
		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	}
	for(int i=1;i<=n;i++){
		int t=1;
		memset(wz,0,sizeof(wz));
		for(int j=i;j<=n;j++){
			if(wz[a[j]]!=0){
				for(int ij=wz[a[j]]+1;ij<t;ij++) wz[f[ij]]=0;
				t=wz[a[j]]+1;
			}
			else{
				f[t]=a[j];
				wz[a[j]]=t;
				t++;
			}
		}
		for(int i=1;i<t;i++) ans[f[i]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]); 
	return 0;
}
