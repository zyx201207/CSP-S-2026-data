#include <bits/stdc++.h>
using namespace std;
const int maxn=200014,maxm=29;
bool ism[maxn][maxm+1],f[maxn],apf=0;
int n,m,a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<=maxm;j++){
			ism[i][j]=(bool)((a[i]&(1<<j))>0);
		}
	}
	for(int i=maxm;i>=0;i--){
		if(apf){
			int ncnt=0;
			bool ptf[maxn]={false};
			memset(ptf,false,sizeof ptf);
			for(int j=1;j<=n;j++){
				if(!f[j]){
					continue;
				}
				if(ism[j][i]){
					ncnt++;
					ptf[j]=1;
				}
			}
			if(ncnt<m){
				continue;
			}
			if(ncnt==m){
				int ans=(1<<30)-1;
				for(int j=1;j<=n;j++){
					if(ptf[j]){
						ans=ans&a[j];
					}
				}
				printf("%d",ans);
				return 0;
			}
			else{
				if(i==0){
					int ans[m]={0},ptr=1,anss=(1<<30)-1;
					memset(ans,0,sizeof ans);
					for(int j=1;j<=n;j++){
						if(ptf[j]){
							ans[ptr++]=a[j];
						}
						if(ptr>m){
							break;
						}
					}
					for(int j=1;j<=m;j++){
						anss=anss&ans[j];
					}
					printf("%d",ans);
					return 0;
				}
				for(int j=1;j<=n;j++){
					f[j]=ptf[j];
				}
			}
		}
		else{
			int ncnt=0,p=(1<<30)-1;
			bool ptf[maxn]={false};
			memset(ptf,false,sizeof ptf);
			for(int j=1;j<=n;j++){
				if(ism[j][i]){
					ncnt++;
					p=p&a[j];
					ptf[j]=1;
				}
			}
			if(ncnt<m){
				if(i==0){
					printf("0");
					return 0;
				}
				continue;
			}
			else if(ncnt==m){
				printf("%d",p);
				return 0;
			}
			else{
				if(i==0){
					int ans[m]={0},ptr=1,anss=(1<<30)-1;
					memset(ans,0,sizeof ans);
					for(int j=1;j<=n;j++){
						if(ptf[j]){
							ans[ptr++]=a[j];
						}
						if(ptr>m){
							break;
						}
					}
					for(int j=1;j<=m;j++){
						anss=anss&ans[j];
					}
					printf("%d",anss);
					return 0;
				}
				apf=1;
				for(int j=1;j<=n;j++){
					if(ptf[j]){
						f[j]=1;
					}
				}
			}
		}
	}
	return 0;
}
/*
后记:
预期100pts.
枚举,O(30n).
*/ 
