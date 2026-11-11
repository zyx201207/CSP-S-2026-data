#include <bits/stdc++.h>
using namespace std;
const long long N=2000005,INF=1e13+5;
int a[N],nx[N],in[N];

int main(){
	freopen("migrate2.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	
	int c,t;cin>>c>>t;
	while(t--){
		int n,d,ans=0;cin>>n>>d;
		memset(nx,0,sizeof(nx));
		memset(in,0,sizeof(in));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int j=i-1;
			while(j>0&&a[j]>=a[i]-d){
				nx[j]++; 
				in[i]++; 
				//lg[j]=max(lg[j],a[i]-a[j]);
				j--;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<nx[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			cout<<in[i]<<" ";
		}
		for(int i=1;i<=n-d+1;i++){
			if(nx[i]==in[i+d+1]&&nx[i]%d==0&&nx[i]!=0)ans++;
		}
		cout<<ans<<endl;
	}
	

	return 0;
} 
