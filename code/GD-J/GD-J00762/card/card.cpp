#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],k,ans[300010];      
int vis[300010];   
bool A=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]<a[i-1]) A=0;
	}
	if(A==1) {
		for(int i=1,j=a[1];i<=n;i++) {
			if(a[i+1]!=j) {
				ans[j]=i;
				j=a[i+1];
			}
		}
		for(int i=1;i<=m;i++) {
			cout<<ans[i]<<" ";
		}
		return 0;
	}
//	if(n<=6000) { //1
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				if(vis[a[j]]>0) {
					while(b[k]!=a[j]) {
						vis[b[k--]]=0;
					}
				}
				else {
					b[++k]=a[j];
					vis[a[j]]=k;
				}
//				cout<<b[k]<<"&"<<k<<" ";
			}
			for(int i=1;i<=k;i++) {
				ans[b[i]]++;
			}
//			cout<<"\n";
			k=0;
			memset(b,0,sizeof(b));  
			memset(vis,0,sizeof(vis));
		}
		for(int i=1;i<=m;i++) {
			cout<<ans[i]<<" ";
		}
//	}
	
	return 0;
}

