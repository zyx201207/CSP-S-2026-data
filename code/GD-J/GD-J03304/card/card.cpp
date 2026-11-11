#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	scanf("%d%d",&n,&m);
	vector<int>sz(n+1),ans(m+1);
	for(int i=1;i<=n;i++)scanf("%d",&sz[i]);
	for(int i=1;i<=n;i++){
		vector<int>find(m+1),desk(n+1);
		int k=1;
		for(int j=i;j<=n;j++){
			if(!find[sz[j]]){
				desk[k]=sz[j];
				find[sz[j]]=k++;
			}else{
				k=find[sz[j]];
				for(int l=k+1;l<=n;l++)find[desk[l]]=0;
			}
		}
		for(int j=1;j<=m;j++)if(find[j])ans[j]++;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]); 
	}
	return 0;
} 
