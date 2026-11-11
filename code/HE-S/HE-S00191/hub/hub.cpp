#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[50005],k[505],a[505][50005],t[505][50005],r[10005][2],ans=1e9+5;
vector<int> mp[50005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][k[i]]>>t[i][k[i]];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>r[i][1]>>r[i][2];
		cout<<ans<<"\n";
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
