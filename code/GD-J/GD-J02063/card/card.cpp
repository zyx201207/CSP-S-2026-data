//´ò60·Ö±©Á¦
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,m,ans[N];
int a[N];
int wz[N];
int vis[N]={0};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++)vis[j]=0;
		int te=1;int zz=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]++;
				wz[++zz]=a[j];
			}
			else{
				for(int k=zz;k>=1;k--){
					vis[wz[k]]--;
					if(wz[k]==a[j]){
						break;
					}
				}vis[a[j]]++;
			}
		}for(int j=0;j<=m;j++){
			if(vis[j]){
				ans[j]+=vis[j];
				cout<<j<<' ';
			}
		}cout<<endl;
	}for(int i=1;i<=m;i++){
		if(ans[i])cout<<ans[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3
*/
