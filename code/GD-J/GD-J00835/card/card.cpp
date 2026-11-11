#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int tong[300010];
int b[500010],sum[500010];
int ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!tong[a[i]]){
			tong[a[i]]=i;
		}else{
			b[tong[a[i]]]=i;
			tong[a[i]]=i;
		}
	}
	sum[0]=0;
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i]+sum[i-1]+1;
		if(b[i]){
			sum[b[i]]+=sum[i];
			sum[i]=0;
		}
		ans[a[i]]=max(ans[a[i]],sum[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
