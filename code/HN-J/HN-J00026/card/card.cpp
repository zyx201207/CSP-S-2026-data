#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=10005;
int a[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int vis[M];
	for(int i=1;i<n;i++){
		int sis[M],six[M];
		int x[M];
		for(int j=i;j<=n;j++){
			sis[a[i]]++;
			if(sis[a[i]]==1)six[a[i]]=i;
			if(sis[a[i]]>=2){
				x[six[a[i]]]+=1;
				x[i+1]-=1;
				sis[a[i]]=0;
			}
		}
		for(int j=i;j<=n;j++){
			x[i]+=x[i-1];
			if(x[i]<=0)vis[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<vis[i]<<" ";
	return 0;
}
