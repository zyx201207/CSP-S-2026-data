#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k,l[300090];
	cin>>n>>m;
	for(i=1;i<n;i++){
		cin>>l[i];
	}for(j=1;j<=n;j++){
		for(i=j;i<=n;i++){
			for(k=1;k<j;k++){
				if(l[k]==l[j]){
					
				}
			}
		}
	}for(i=1;i<=m;i++){
		cout<<i<<" ";
	}
	return 0;
}
