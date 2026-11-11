#include<bits/stdc++.h>
using namespace std;
int n,m,top;
int a[500010];
int sumk[500010];
int ans[200020];
int kk[200020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		if(kk[a[i]]!=0)
			sumk[i]=kk[a[i]];
		kk[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(sumk[j]!=0){
				j=sumk[j];
			}
			if(sumk[j]==0){
				ans[a[j]]++;
			}	
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
