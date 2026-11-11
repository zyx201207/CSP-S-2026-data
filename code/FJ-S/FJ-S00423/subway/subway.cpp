#include<bits/stdc++.h>
using namespace std;
const int N=5.1e5;
int c,n,m,d,q;
int w[N],k[N],a[N][1000],t[N][1000],x,y,ans=1e9,T;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c;
	if(c>=7&&c<=11){
		cin>>n>>m>>d>>q;
		cin>>w[1]>>w[2];
		for(int i=1;i<=n;i++){
			cin>>k;
			if(k==1){
				cin>>a[i][1]>>t[i][1];
			}else{
				cin>>a[i][1]>>t[i][1]>>a[i][2]>>t[i][2];
				ans=min(ans,t[i][1]+t[i][2]);
			}
		}
		cin>>q;
		while(q--){
			cin>>x>>y;
			cout<<ans+w[1]+w[2];
		}
	}else if(12<=&&c<=19){
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>T;
			}
		}
		cin>>q;
		while(q--){
			cin>>x>>y;
			cout<<T*2+w[x]+w[y];
		}
	}
	return 0;
}
