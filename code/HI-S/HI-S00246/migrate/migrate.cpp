#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+1;
int x[maxn],xx[maxn];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		int n,d,ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		xx[0]=0;xx[1]=x[1];
		for(int i=2;i<=n;i++) xx[i]=x[i]-x[1];
		for(int i=3;i<n;i++){
			for(int l=1;l+i<=n;l++){
				int r=l+i;
				if(xx[r]%d!=0&&xx[r]>d){
					ans++;
				}}}
		 cout<<ans<<endl;
	}
	
	return 0;
}
