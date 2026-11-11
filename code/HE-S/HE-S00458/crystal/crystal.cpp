#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cost=0,ans=INT_MIN,a[500005],c[10000][10000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=a[1];i<=a[n];i++){
		int t=0;
		for(int j=0;j<=n;j++){
			if(a[j]>i){
				c[i][j]=-1;
				continue;
			}
			c[i][j]=i-a[j];
			t+=1;
			cost+=c[i][j];
		}
		if(cost<=m) ans=max(t,ans);
	}
	cout<<ans<<"\n";
	return 0;
}
