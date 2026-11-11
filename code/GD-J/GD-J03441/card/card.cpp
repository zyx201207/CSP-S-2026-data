#include <bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int kxt=-1;
}a[500010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].num==a[j].num){
				a[i].kxt=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int idx=1;
		bool sum[500010];
		for(int i=0;i<=n+1;i++)sum[i]=0;
		while(idx<=n){
			if(a[idx].kxt==-1){
				sum[idx]=1;
			}else{
				idx=a[idx].kxt;
			}
		}
		for(int i=1;i<=n;i++){
			if(sum[i]==1)ans[i]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
