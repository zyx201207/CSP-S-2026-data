#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+5;
const int inf=INT_MAX;
const ll lnf=LLONG_MAX;
using namespace std;

int n,m,vis[N],lt[N],maxn[N],a[N];

int solve(int x){
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[x]<i)continue;
		if(maxn[vis[x]]<i||a[vis[x]]==a[i]){
			res++;
//			cout<<i<<'\n';
		}
	} 
	return res;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lt[a[i]]=vis[a[i]];
		vis[a[i]]=i; 
	}
	for(int i=n;i>=1;i--){
		maxn[i]=max(maxn[i+1],lt[a[i+1]]);
	}
	for(int i=1;i<=m;i++){
		cout<<solve(i)<<" ";
	}
	return 0;
} 
