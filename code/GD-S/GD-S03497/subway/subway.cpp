#include<bits/stdc++.h> 
using namespace std;
struct aa{
	long long a,t;
}a[505][20005];
long long c,n,m,d,q,w[500005],k,s,e,ans,b[505][505];
long long sp[505],ep[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j].a>>a[i][j].t,b[i][a[i][j].a]=1; 
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		ans+=w[s]+w[e];
		for(int j=1;j<=n;j++)if(b[j][s]==1)sp[j]++;
		for(int j=1;j<=n;j++)if(b[j][e]==1)ep[j]++;
		for(int j=1;j<=n;j++)if(sp[j]==1&&ep[j]==1)ans+=a[i][j].t;
		cout<<ans<<endl;
	}
}
