#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=5e5+5;
const ll N=3e5+5;
bool vis[N];
ll n,m;
ll a[M],b[N],p[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
//	freopen("card1.in","r",stdin);
//	freopen("card1.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ll l=i;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]) vis[a[j]]=1;
			else l=j;
		}for(int i=l;i<=n;i++){
			b[a[i]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<b[i];
		if(i<m) cout<<' ';
	}
	return 0;
}
