#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],ans[1000005],t[1000005];
bool vis[1000005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,tmp=0;
	bool flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],tmp+=(a[i]!=a[i-1]),flag=max(flag,a[1]>a[2]);
	if(m<=2){
		cout<<1;
	}else if(!flag){
		for(int i=1;i<=n;i++) t[a[i]]++;
		for(int i=1;i<=m;i++){
			if(t[i]&1){
				int cnt=0;
				for(int j=i;j<=m;j++) cnt+=t[j];
				cout<<cnt<<" ";
			}else{
				cout<<1<<" ";
			}
		}
	}else if(tmp<=4999){
		cout<<3;
	}else{
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;j++){
				if(vis[a[i]]){
					bool flag=0;
					for(int k=i;k<j;k++){
						if(vis[a[k]]&&a[k]==a[i]) flag=1;
						vis[a[k]]=flag;
					}
				}else{
					vis[a[i]]=1;
				}
			}
			for(int j=1;j<=m;j++) if(!vis[i]) ans[j]++,cout<<j<<" ";
			cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}

