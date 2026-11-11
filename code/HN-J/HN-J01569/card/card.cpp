#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10; 
int n,m;
int a[N],stk[N],ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		int tp=0;
		for(int j=i;j<=n;j++){
			for(int k=0;k<=tp;k++){
				if(stk[k]==a[j]){
					tp=k-1;
				}
			}
			stk[++tp]=a[j];
		}
		for(int j=0;j<=tp;j++){
			if(!vis[stk[j]]) ans[stk[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
//Trick||Treat!

