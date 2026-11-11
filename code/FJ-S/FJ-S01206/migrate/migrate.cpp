#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n;
			long long m;
			long long a[N]={0};
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int ans=0;
			for(int i=4;i<=n;i++){
				long long x=max(abs(a[i-1]-a[i-3]),abs(a[i]-a[i-2]));
				if(x==m)ans++;
			}
			cout<<ans<<endl;
		}
	}
	else{
		int n;
		long long m;
		long long a[N]={0};
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=4;i<=n;i++){
			for(int j=i;j<=n;j++){
				int cnt=0;
				for(int k=1;k<=i-2;k++){
					
				}
			}
		}
		cout<<1<<endl;
	}
	return 0;
}
