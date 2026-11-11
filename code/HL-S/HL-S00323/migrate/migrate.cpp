#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int u,t;
int n;
long long d;
long long a[N];
long long b[N];
long long rt=0;
long long io=0;
long long ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>u>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
		}
		if(n==1||n==2||n==3){
			cout<<0<<endl;
			continue;
		}
		if(abs(a[n]-a[1])<=d){
			cout<<0<<endl;
			continue;
		}
		io=b[2];
		for(int i=2;i<=n;i++){
			if(io!=b[i]){
				rt=1;
				break;
			}
		}
		if(rt==0){
			long long ty=d/io;
			for(int i=4;i<=n;i++){
				if(i-1>ty&&(i-1)%ty!=0&&(i-1)/ty<2){
					ans+=n-i+1;
				}
			}
		}
		rt=0;
		cout<<ans<<endl;
		ans=0;
	}
	
	
	
	return 0;
}
