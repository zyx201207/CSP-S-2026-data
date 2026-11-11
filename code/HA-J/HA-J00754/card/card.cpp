#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],bj,dp[100005],ans[100005],bj1[5005][3005],bj2[200005][4];
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) bj=1;
	}
	if(bj==0) {
		for(int i=n;i>=1;i--){
			dp[a[i]]=1;
			for(int j=1;j<=m;j++){
				if(dp[j]==1) ans[j]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(m<=2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				bj2[i][j]=bj2[i-1][j];
			}
			bj2[i][a[i]]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(bj2[j-1][a[j]]-bj2[i-1][a[j]]>0){
					while(st.top()!=a[j]) st.pop();
				}else{
					st.push(a[j]);
				}
			}
			while(!st.empty()){
				ans[st.top()]++; 
				st.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bj1[i][j]=bj1[i-1][j];
		}
		bj1[i][a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(bj1[j-1][a[j]]-bj1[i-1][a[j]]>0){
				while(st.top()!=a[j]) st.pop();
			}else{
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			ans[st.top()]++; 
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
