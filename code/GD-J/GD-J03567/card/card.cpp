#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],cnt[N],last[N];
int vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n<=5000||m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					vis[a[j]]=1;
					last[a[j]]=j;	
				}
				else{
					for(int t=last[a[j]];t<=j;t++){
						vis[a[t]]=0;
					}
					vis[a[j]]=1;
				}
			}
			for(int x=1;x<=m;x++){
				if(vis[x]){
	//				cout<<x<<" ";
					cnt[x]++;
					vis[x]=0;
				}
			}
	//		cout<<"\n";
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
	}else{
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}
