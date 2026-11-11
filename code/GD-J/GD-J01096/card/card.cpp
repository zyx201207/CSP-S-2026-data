#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m;
int a[50005];
int l[30005];
int ans[30005];
int x[50005][30005];
int cnt[50005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(l[a[i]]==0){
			cnt[i+1]++;
			for(int j=1;j<=m;j++){
				x[i][j]=x[i+1][j];
			}
			x[i][a[i]]++;
			l[a[i]]=i;
		}
		else{
			int v=l[a[i]];
			cnt[v]++;
			for(int j=1;j<=m;j++){
				x[i][j]=x[v][j];
			}
			l[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)ans[i]+=x[j][i];
		cout<<ans[i]<<" ";
	}
	return 0;
}  
