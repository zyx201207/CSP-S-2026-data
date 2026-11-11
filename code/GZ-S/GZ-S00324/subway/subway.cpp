//GZ-S00324 贵阳市第十八中学 李翼辰
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500000+50],a[500000+50],t[500000+50];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
	}
	int bei=1;
	while(q--){
		int ans=0;
		int x,y;cin>>x>>y;
		ans+=w[x]+w[y];
		cout<<ans+t[2]*bei<<endl;
		bei++;
	}
	return 0;
} 
