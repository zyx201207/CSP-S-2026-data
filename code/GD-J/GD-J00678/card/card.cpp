#include<bits/stdc++.h>
using namespace std;
int n,m,d[500010],ld[500010],ans[500010];
bool b[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[d[j]]){
				for(int k=ld[d[j]];k<=j;k++) b[d[k]]=0;
			}
			b[d[j]]=1;
			ld[d[j]]=j;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=int(b[i]);
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
