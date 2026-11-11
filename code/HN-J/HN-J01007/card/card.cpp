#include<bits/stdc++.h>//±©Á¦ 
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],vis[M],pos[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=++cnt;
				pos[cnt]=a[j];
			}
			else{
				int id=vis[a[j]];
				for(int k=id+1;k<=cnt;k++){
					vis[pos[k]]=0;
					pos[k]=0;
				}
				cnt=id;
			}
		} 
		for(int j=1;j<=n;j++){
			if(vis[a[j]])ans[a[j]]++;
			vis[a[j]]=0;
			pos[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
