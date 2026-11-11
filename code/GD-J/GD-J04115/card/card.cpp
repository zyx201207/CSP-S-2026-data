#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum[300010]={};
		for(int j=i;j<=n;j++){
			if(sum[a[j]]==0)sum[a[j]]=j;
			else{
				for(int x=1;x<=m;x++){
					if(sum[x]>sum[a[j]])sum[x]=0;
				}
				sum[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(sum[j])ans[j]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
