//GZ-J00571 贵阳实验二中 刘子墨
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],k,g[500005];
bool check(int x){
	for(int i=1;i<=k;i++)
		if(g[i]==x) return i;
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			int y=check(a[j]);
			if(y) k=y;
			else g[++k]=a[j];
		}
		for(int j=1;j<=k;j++) sum[g[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
