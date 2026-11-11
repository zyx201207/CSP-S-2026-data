#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
long long w[N],t[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long a1,a2;
			cin>>a1>>a2;
			t[i][a1]=a2;
		}
	}
	while(q--){
		long long ans,x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(long long i=1;i<=n;i++){
			if(t[i][x]!=0||t[i][y]!=0){
			ans=ans+t[i][x]+t[i][y];
			cout<<ans<<"\n";
			ans=-1;
			break;}
		}
		if(ans!=-1){
			for(int i=1;i<=n;i++){
				ans+=t[i][x];
				ans+=t[i][y];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
 } 
