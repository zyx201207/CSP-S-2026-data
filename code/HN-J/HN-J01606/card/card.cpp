#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10,M=3e5+10,INF=1e9;
int n,m,a[N],ans[M],vis[M],f[N];
void Clear(){
	for(int i=1;i<=m;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		f[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(f[k]) continue;
				if(a[k]==a[j]){
					for(int l=k;l<j;l++){
						f[l]=1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(f[j]) continue;
			ans[a[j]]++;
			//cout<<a[j]<<' ';
		}
		//cout<<'\n';
		Clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
