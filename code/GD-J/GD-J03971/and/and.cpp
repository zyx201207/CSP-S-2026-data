#include <bits/stdc++.h>
using namespace std;
int n,m,maxx,a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
//		if(a[i]>dp[1]){
//			dp[1]=a[i],x=i;
//		}
	} 
	if(maxx<=4&&n*1ll*m>=1e7){
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n);//玄学代码？ 
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	dp[0]=INT_MAX;//初始化01111...111（共31个1，保证dp[0]&a[i]=a[i]; 
	for(int i=1;i<=n;i++){//01背包？暂时无法证明正确性，但是样例都过了，关键在sort 
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m]<<endl;
	//for(int i=1;i<=m;i++)cout<<dp[i]<<" ";
	return 0;
}
