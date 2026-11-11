#include<bits/stdc++.h>
using namespace std;
int p[500005],ans[300005]; 
vector<int>point[300005];
int cu[300005],cut[300005],pp[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<=m;i++)ans[i]=pp[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		point[p[i]].push_back(i);
		cu[p[i]]++;
	}
	for(int i=0;i<=m;i++)cut[i]=cu[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cu[j]=cut[j],pp[j]=0;
		}
		for(int j=1;j<i;j++){
			cu[p[j]]--,pp[p[j]]++;
		}
		for(int j=i;j<=n;j++){
			ans[p[j]]++;
			if(cu[p[j]]>1){
				for(int k=j+1;k<point[p[j]][pp[p[j]]+1];k++){
					cu[p[k]]--,pp[p[k]]++;
				}
				j=point[p[j]][pp[p[j]]+1];
				cu[p[j]]-=2,pp[p[j]]+=2;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

