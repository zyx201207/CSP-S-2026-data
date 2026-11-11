#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[1000],a[10005],t[10005],x,y,ans,h[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			if(i>1) h[j]=min(h[j],t[j]);
			else h[j]=t[j];
		} 
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int j=x;j<=y;j++){
			ans+=h[j];
		}
		cout<<ans<<"\n";
	} 
	return 0;
}


