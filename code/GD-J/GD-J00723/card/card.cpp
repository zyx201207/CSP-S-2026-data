#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m;
int a[N],ans[N],x[N];
int vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(x,0,sizeof x);
		memset(vis,0,sizeof vis);
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				x[++cnt]=a[j];
				vis[a[j]]++;
			}
			else{
				bool f=true;
				for(int k=1;k<=cnt;k++){
					if(f==false){
						vis[x[k]]--;
						x[k]=0;
					}
					if(x[k]==a[j]){
						f=false;
					}
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[x[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
