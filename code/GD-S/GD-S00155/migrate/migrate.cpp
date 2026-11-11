#include<bits/stdc++.h>
using namespace std;
int v[5005][5005];
int ml[5005][5005];
int n,m,a[5005],ans;
void dfs(int s,int e,int l){
	//cout<<s<<" "<<e<<" "<<l<<"\n";
	if (l==ml[s][e]){
		v[s][e]++;
	}	
	if (e==n){
		return ;
	}

	for (int i=e+1;i<=n;i++){
		if (a[i]-a[e]<=m){
			if (ml[s][i]>l+1){
				v[s][i]=0;
				ml[s][i]=l+1;
			}
			dfs(s,i,l+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		ans=0;
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		memset(ml,10623,sizeof ml);
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			dfs(i,i,1);
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				//cout<<ml[i][j]<<" ";
				if (v[i][j]==2){
					ans++;
				}
			}
			//cout<<"\n";
		}
		cout<<ans<<"\n";
	}

	return 0;
	/**/
}
