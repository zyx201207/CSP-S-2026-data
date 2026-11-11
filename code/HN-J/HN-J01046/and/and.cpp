#include <bits/stdc++.h>
using namespace std;
int n,m;int nn[200001];int maxi=-999;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&nn[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxi=max(maxi,nn[i]);
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<=n;i2++){
				if(i==i2) continue;
				maxi=max(maxi,(nn[i]&nn[i2]));
			}
		}
	}
	cout<<maxi;
	return 0;
} 
