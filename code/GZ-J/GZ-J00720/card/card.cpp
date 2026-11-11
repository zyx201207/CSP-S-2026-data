//GZ-J00720 王煜航
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],cn[300001],ans[300001],mid[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){

			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					j=k;
				}
			}
			mid[a[j]]++;
			j++;
		}for(int k=1;k<=m;k++){
			if(mid[k]) ans[k]++;
			mid[k]=0;
		}


	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
