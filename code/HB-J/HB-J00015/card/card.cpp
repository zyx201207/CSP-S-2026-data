#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5001],n,m,c[5001],d[5001];
bool b[5001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(c,0,sizeof c);
			memset(b,0,sizeof b);
			for(int j=i;j<=n;j++){
				if(c[a[j]]==0) c[a[j]]=j;
				else for(int t=c[a[j]];t<j;t++) b[t]=1,c[a[j]]=j,c[a[t]]=0;
			}
			for(int j=i;j<=n;j++){
				if(b[j]==0) d[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<d[i]<<' ';
	}
}
