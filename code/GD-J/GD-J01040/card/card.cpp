#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[300005],f[300005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=j;
			}else{
				for(int p=f[a[j]]+1;p<j;p++){
					if(a[p]==a[j]) continue;
					f[a[p]]=0;
				}
			}
		}for(int j=1;j<=m;j++){
			if(f[j]!=0){
				ans[j]++;
			}
		}
	}for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
