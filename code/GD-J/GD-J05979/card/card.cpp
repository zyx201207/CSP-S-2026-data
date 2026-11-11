#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3fLL;
const int N=5e5+5;
int a[N];
int ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int game=1;
	while(n>0){
		bool vis[N]={0};
		bool bl=false;
		for(int i=game;i<=n;i++){
			for(int j=game;j<=i;j++){
				if(bl==true)vis[j]==1,n--;
				if(a[i]==a[j])bl=1,vis[j]==1,n--;
			}
		}
		for(int i=game;i<=n;i++){
			if(!vis[i])ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
