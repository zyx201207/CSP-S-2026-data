#include <bits/stdc++.h>
using namespace std;
int pai[500005],zl[300005],wz[300005],zm[500005],mj[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,bst=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&pai[i]);
		bst=max(bst,pai[i]);
	}
	for(int i=1;i<=n;i++){
		int zmjs=i-1;
		for(int j=i;j<=n;j++){	
			if(zl[pai[j]]!=0){
				for(int k=wz[pai[j]];k<=zmjs;k++){
					zl[zm[k]]=0;
					wz[zm[k]]=0;
					zm[k]=0;
				}
				zmjs=wz[pai[j]]-1;
				wz[pai[j]]=0;
			}
			zm[zmjs++]=pai[j];
			zl[pai[j]]=1;
			wz[pai[j]]=zmjs;
		}
		for(int j=1;j<=bst;j++){
			if(zl[j]!=0){
				mj[j]++;
				wz[j]=0;
				zl[j]=0;
			}
		}
	}
	for(int i=1;i<=bst;i++){
		printf("%d ",mj[i]);
	}
}
