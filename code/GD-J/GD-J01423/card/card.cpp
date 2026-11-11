#include<bits/stdc++.h>

using namespace std;
const int N=500005,M=300005,INF=600000;
int a[N],be[M],nx[N],ans[M];
//be[i]:目前花色i的最后位；nx[j]: a[j]后下一个有效花色 ans[i]: 答案 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		nx[i]=INF;
	}	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(be[a[i]]!=0){
			nx[be[a[i]]]=i;
		}be[a[i]]=i;
		
	}

	int res=0;
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			while(nx[j]!=INF){
				j=nx[j];
			}
			//printf("ans[ %d (a[ %d ])]++\n",a[j],j);
			ans[a[j]]++;		
			j++;	
		}

	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
		//cout<<<<" ";
	}
	return 0;
}
