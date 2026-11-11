#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005],pz[500005],cnt,ans[500005];
unordered_map<int,int>mp;
unordered_map<int,int>mp2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
//	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp2[a[i]]++;
	}
	if(n<=500){
		for(int k=1;k<=n;k++){
			mp.clear();
			cnt=0;
			for(int i=1+k-1;i<=n;i++){
				if(!mp[a[i]]){
					pz[++cnt]=a[i];
					mp[a[i]]=cnt;
				}
				else{
					for(int j=mp[a[i]]+1;j<=cnt;j++){
						mp[pz[j]]=0;
//						printf("%d %d ",i,pz[i]);
					}
					cnt=mp[a[i]];
//					printf("\n");
				}
			}
			for(int j=1;j<=cnt;j++){
//				printf("%d ",pz[j]);
				sum[pz[j]]++;
			}
//			printf("\n"); 
		}
		for(int i=1;i<=m;i++){
			printf("%d ",sum[i]);
		}
	}
	else{
		for(int i=m,j=0;i>=1;i--,j++){
			ans[++cnt]=n-j-mp2[i]+1;
		}
		for(int i=cnt;i>=1;i--){
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
