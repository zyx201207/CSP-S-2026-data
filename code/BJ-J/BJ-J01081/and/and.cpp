#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200020;
int a[maxn],temp[maxn];
bool vis[maxn];
int fp(int a){
	int res=1;
	int base=2;
	while(a>0){
		if(a&1) res*=base;
		base*=base;
		a>>=1;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[i]=1;
	}
	int f=fp(31);
	
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			temp[j]=-1;
		}
		int t=0;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				if((a[j]>>i)&1){
					cnt++;
				}
				else{
					vis[j]=0;
					temp[++t]=j;
				}
			}
		}
		int res=f-1;
		if(cnt<m){
			for(int j=1;j<=t;j++){
				if(temp[j]>-1){
					vis[temp[j]]=1;
				}			
			}
			if(i<=0){
				for(int j=1;j<=n && m;j++){
					if(vis[j]){
						res&=a[j];
						m--;
					}
				}
				printf("%d\n",res);
				break;
			}
		}
		else if(cnt==m){		
			for(int j=1;j<=n;j++){
				if(vis[j]){
					res&=a[j];
				}
			}
			printf("%d\n",res);
			break;
		}
		else if(cnt>m && i<=0){
			for(int j=1;j<=n && m;j++){
				if(vis[j]){
					res&=a[j];
					m--;
				}
			}
			printf("%d\n",res);
			break;
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}