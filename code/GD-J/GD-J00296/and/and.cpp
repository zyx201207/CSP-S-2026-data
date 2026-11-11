#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt=0;
int n,m;
int f[200005];
bool b[200005];
void dfs(int c,int d){
	if(c>m){
		long long ma=a[f[1]];
		for(int k=1;k<=m;k++){
		ma=(a[f[k]]&ma);
		}
		cnt=max(cnt,ma);
		return ;
	}
	for(int k=d;k<=n;k++){
		if(b[k]==false){
			b[k]=true;
			f[c]=k;
			dfs(c+1,k+1);
			b[k]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int k=1;k<=n;k++)cin>>a[k];
	dfs(1,1);
	cout<<cnt;
	return 0;
}
