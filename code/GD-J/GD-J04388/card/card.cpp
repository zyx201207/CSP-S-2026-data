#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long ans[300010];
vector<int> r[300010];
int dp[500010];
int l[300010]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(l[a[i]]==0){
			l[a[i]]=i;
			for(int j=0;j<r[a[i+1]].size();j++){
				ans[r[a[i+1]][j]]++; 
				r[a[i]].push_back(r[a[i+1]][j]);
			}
			ans[a[i]]++;
			r[a[i]].push_back(a[i]);
		}
		else{
			for(int j=0;j<r[a[i]].size();j++){
				ans[r[a[i]][j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3
*/
