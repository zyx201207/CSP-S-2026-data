#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500010];
int t[201][210];
int a[210][210];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int s,e,ans=0;
		cin>>s>>e;
		ans+=w[s];
		ans+=w[e];
		for(int now=s;now!=e;){
			ans=ans+t[now][1]+t[now][2];
			now=a[now][2];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
