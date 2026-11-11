#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool b[300040];
	int idx[300010];
	int ans[500010];
	int a[500010];
	int p[500010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int id=0;
		memset(b,sizeof p,0);
		for(int j=i;j<n;j++){
			if(!b[a[j]]){
				p[id]=a[j];
				b[a[j]]=1;
				idx[a[j]] = id;
			}else{
				id=idx[a[j]];
			}
			id++;
		}
		for(int j=0;j<id;j++){
			ans[p[j]]++; 
		}
	}
	for(int i=0;i<m;i++){
		printf("%d",p[i]);	
	}
	printf("\n");
	for(int i=0;i<m;i++){
		printf("%d",ans[i]);	
	}
}
