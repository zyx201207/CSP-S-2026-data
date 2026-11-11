#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],c[500005],d[500005],e[500005],s,ans;
signed main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==-1&&a[i]!=a[i-1])s=1;
		b[a[i]]=-1;
	}
	if(s==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]&&i>1)b[a[i-1]]=ans;
			ans++;
		}
		b[a[n]]=ans;
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=i;
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=-1){
				for(int k=b[a[j]];k<=j;k++){
					c[k]=1;
				}
			}
			b[a[j]]=j;
		}
		for(int j=t;j<=n;j++){
			if(c[j]==0){
				d[a[j]]++;
				e[a[j]]=1;
			}
		}
		memset(b,-1,sizeof(b));
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
