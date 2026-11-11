#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,a[500010],check[300010],ans[300010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=n;i++){
		for(int j=i;j<=n;j++){
			if(check[a[j]])
			check[a[j]]=j;
	 }
		for(int j=1;j<=m;j++)
			if(check[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i];
	return 0;
} 
