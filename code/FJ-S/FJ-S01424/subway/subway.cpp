#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,b;
int Walk[500005],Line[50005][505];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(Line,0,sizeof(Line));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>Walk[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>b;
			Line[a][i]=b;
		}
	}
	for(int i=1;i<=q;i++){
		long long ans=0;
		cin>>a>>b;
		ans+=Walk[a]+Walk[b];
		for(int i=1;i<=n;i++){
			if(Line[a][i]!=0) ans+=Line[a][i];
			if(Line[b][i]!=0) ans+=Line[b][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
