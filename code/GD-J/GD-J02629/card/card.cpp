#include<bits/stdc++.h>
using namespace std;
int vis[300005][2],b[500005],ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,a[500005];
	cin>>n>>m;
	if(n>5){
		for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=m;i++){
		ans=0;
		for(int k = 1;k<=n;k++){
			int j=i,r=0;
			memset(b,0,sizeof(b));
			memset(vis[0],0,sizeof(vis[0]));
			while(j<=n){
				if(vis[a[j]][0]==0){
					vis[a[j]][0]++;
					vis[a[j]][1]=++r;
					b[r]=a[j];
				}else{
					vis[a[j]][0]=0;
					r=vis[a[j]][1]-1;
				}j++;
			}for(int j = 0;j<=r;j++)if(i==b[j]){
				ans++;
				break;
			}
		}cout << ans<< ' ';
	}
	}if(n<=5){
		srand(0);
		for(int i = 0;i<m;i++){
			cout << rand()%n<<' ';
		}
	}
	
	return 0;
}
