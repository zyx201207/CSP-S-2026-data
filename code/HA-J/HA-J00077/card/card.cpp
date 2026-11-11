#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,m;
int a[N];
int pos[N];
long long f[N],g[N],ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!pos[a[i]]) f[i]=i,pos[a[i]]=i;
		else f[i]=pos[a[i]];
	}
	for(int i=1;i<=n;i++){
		if(f[i]==i){
			ans[a[i]]+=g[i]+1;
			f[i]=i+1;
		}
		g[f[i]]+=g[i]+1;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	
	return 0;
}
