#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=2e6+10;
int c,t,n,d,x[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int f=0,id=0;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d){
					if(f==0)id=j,f=1;
					int cnt=0;
					for(int k=i+1;k<id;k++){
						cnt+=(x[j]-x[k]<=d);
					}
					if(cnt==2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
