#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],tong[M],t,sz[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		fill(tong+1,tong+1+m,0);
		fill(sz+1,sz+1+n,0);
		t=0;
		for(int j=i;j<=n;j++){
			tong[a[j]]++;
			if(tong[a[j]]==1) sz[++t]=a[j];
			else{
				int q=0;
				for(int k=1;k<=t;k++){
					if(sz[k]==a[j]){
						q=k;
						break;
					}
				}
				for(int k=q;k<=t;k++) tong[sz[k]]--;
				t=q;
				sz[t]=a[j];
			}
		}
		for(int i=1;i<=m;i++) if(tong[i]>=1) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
//10 3
//3 1 2 1 3 2 3 1 2 1
