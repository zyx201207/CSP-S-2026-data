#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,ans=0,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int a;cin>>a;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;ans=0;
		for(int j=1;j<=k;j++){
			int a,b;cin>>a>>b;
			ans+=b;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<ans<<endl;
	}
	return 0;
}
