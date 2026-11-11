#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],mem[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(mem,0,sizeof(mem));
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(mem[a[j]] && mem[a[j]]<=cnt) cnt=mem[a[j]];
			else mem[a[j]]=++cnt;
			for(int k=1;k<=m;k++) if(mem[k]>cnt) mem[k]=1e9;
		}
		for(int j=1;j<=m;j++)ans[j]+=mem[j]<=cnt&&mem[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' '; 
	return 0;
}
