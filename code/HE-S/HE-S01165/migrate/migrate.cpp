#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[200005];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%d",&x[j]);
		}
		int flag[200005]={0};
		for(int j=1;j<=n;j++){
			for(int k=n;k>j;k--){
				if(x[k]-x[j]>=d){
					flag[k]++;
				}
			}
		}
		int all=0;
		for(int j=1;j<=n;j++){
			if(flag[j]>1){
				all++;
			}
		}
		cout<<all;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
