#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[5005][3005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	if(n<=5000&&m<=3000){
		memset(b,-1,sizeof(b));
		for(int i=n;i>=1;i--){
//			cout<<b[a[i]]<<endl;
			c[i][a[i]]=1;
			if(b[a[i]]!=-1){
				for(int j=1;j<=m;j++){
					if(j==a[i]){
						continue;
					}
					if(c[b[a[i]]][j]){
						c[i][j]=1;
					}
				}
			}else{
				for(int j=1;j<=m;j++){
					if(j==a[i]){
						continue;
					}
					if(c[i+1][j]){
						c[i][j]=1;
					}
				}
			}
/*			for(int j=1;j<=m;j++){
				cout<<c[i][j]<<" ";
			}
			cout<<endl;*/
			for(int j=1;j<=m;j++){
				ans[j]+=c[i][j];
			}
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
//		return 0;
//	}
	fclose(stdin);
	fclose(stdout);
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
