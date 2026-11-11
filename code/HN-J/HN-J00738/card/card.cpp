#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],p[300005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[a[j]]==1){
				for(int k=j-1;k>=1;k--){
					if(a[k]==a[j]){
						break;
					}
					p[a[k]]=0;
				}
			}
			p[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(p[j]==1){
				ans[j]++;
			}
			p[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
//unique(b+1,b+k+1)-b;
//fa[x]=get(fa[x])
//f[get(y)]=get(x);
