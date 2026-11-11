#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int a[500005],id[300005],ans[300005],k[500005];
signed main(){
	fast;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=0,len=0;
	while(++t<=n){
		memset(id,0,sizeof(id));
		memset(k,0,sizeof(k));
		for(int i=t;i<=n;i++){
			if(!id[a[i]])id[a[i]]=++len,k[len]=a[i];
			else{
				for(int j=id[a[i]]+1;j<=len;j++)id[k[j]]=0;
				len=id[a[i]];
			}
		}
		for(int i=1;i<=m;i++)if(id[i])ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
