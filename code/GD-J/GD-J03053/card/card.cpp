#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int last[300005],nxt[500005],pev[500005];
int o[300005];
bool f[500005],b[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(last,0,sizeof(last));
		memset(nxt,0,sizeof(nxt));
		memset(f,1,sizeof(f));
		memset(b,0,sizeof(b));
		nxt[i-1]=i;
		pev[i]=i-1;
		for(int j=i;j<=n;j++){
			if(last[a[j]]!=0&&f[last[a[j]]]){
				for(int k=last[a[j]];k<j;k++)  f[k]=0;
				nxt[pev[last[a[j]]]]=j;
				pev[j]=pev[last[a[j]]];
			}
			last[a[j]]=j;
			nxt[j]=j+1;
			pev[j+1]=j;
		}
		for(int j=nxt[i-1];j<=n&&j!=0;j=nxt[j]){
			//cout<<j<<' ';
			if(!b[a[j]])  b[a[j]]=1,o[a[j]]++;
		}//cout<<'\n';
	}
	for(int i=1;i<=m;i++)  cout<<o[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
