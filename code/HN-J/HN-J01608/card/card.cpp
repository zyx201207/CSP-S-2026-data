#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],vis[500005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]!=a[j-1])ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
