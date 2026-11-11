#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m;
int a[N],b[N],bn,f[N],anss[N],af[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int g=0;g<n;g++){
		for(int i=g+1;i<=n;i++){
			if(f[a[i]]>0){
				for(int j=f[a[i]];j<=bn;j++) b[j]=0;
				bn=f[a[i]]-1;
				f[a[i]]=0;
			}
			bn++;
			b[bn]=a[i];
			f[a[i]]=bn;
		}
		for(int j=1;j<=bn;j++){
			if(b[j]>0 && af[b[j]]==0){
				anss[b[j]]++;
				af[b[j]]=1;
			}	
		}
		for(int j=1;j<=N;j++) af[j]=0;
		for(int j=1;j<=N;j++) b[j]=0;
		for(int j=1;j<=N;j++) f[j]=0;
		bn=0;
	}
	for(int i=1;i<=m;i++) printf("%d ",anss[i]);
	return 0;
}
