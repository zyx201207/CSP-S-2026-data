#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum,ans[1000005],b[1000005],vis[1000005],l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++){
			l=0;
			memset(vis,0,sizeof(vis));
			memset(b,0,sizeof(b));
			for(int j=i;j<=n;j++){
				if(vis[a[j]]==0){
					l++;
					b[l]=a[j];
					vis[a[j]]=l;
				}else{
					long long llo=vis[a[j]];
					for(int k=vis[a[j]]+1;k<=l;k++){
						vis[b[k]]=0;
						b[k]=0;
					}
					l=llo;
				}
		}
			for(int j=1;j<=l;j++){
				ans[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
    }
    if(m==2){
		long long suma=0,sumb=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) suma++;
			if(a[i]==2) sumb++;
		}
		cout<<suma<<" "<<sumb;
		return 0;
    }
    for(int i=1;i<=n;i++){
		vis[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		sum+=vis[i];
		cout<<sum<<" ";
	}
	return 0;
}
