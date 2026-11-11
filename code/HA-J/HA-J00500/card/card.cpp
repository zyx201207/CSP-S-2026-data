#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],game[500005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		int cnt=0;
		for(int i=q;i<=n;i++){
			if(!vis[a[i]]){
				cnt++;
				game[cnt]=a[i];
				vis[a[i]]=1;
			}else{
				for(int j=cnt;j>=1;j--){
					if(game[j]==a[i]){
						cnt=j;
						break;
					}
					vis[game[j]]=0;
					game[j]=0;
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			vis[game[i]]=0;
			ans[game[i]]++;
			game[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
