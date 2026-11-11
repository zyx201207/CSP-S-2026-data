#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[100001],g,s[100001],t[100001],x,y,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>g;
		for(int j=1;j<=g;j++)cin>>s[j]>>t[j];
		sort(t+1,t+1+g);
		for(int j=1;j<=n;j++)ans+=t[j];
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=ans+a[x]+a[y];
		cout<<ans<<endl;
	}
	return 0; 
}
