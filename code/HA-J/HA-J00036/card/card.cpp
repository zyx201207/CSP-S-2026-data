#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[5005],c[5005],g[3005][5005],ans[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]][++c[a[i]]]=i;
	}
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++){
		if(g[a[j]][c[a[j]]]!=j)
			j=g[a[j]][c[a[j]]];
		ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
