#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,a,b,z;
long long w[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	    cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a>>b;
		if(i==1) z=b;
	}
	while(q--){
		cin>>x>>y;
		long long ans=w[x]+w[y]+z+z;
		cout<<ans<<endl;
	} 
	return 0;
}
