#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N],f[400],b[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			f[i]=1e7;
		}
		for(int i=2;i<=n;i++){
			if(x[i]-x[1]<=d){
				f[i]=1;
			}else{
				for(int j=i-1;j>=1;j--){
					b[j]=1e7;
					if(x[i]-x[j]<=d)b[j]=f[j]+1;
				}
				sort(b+1,b+i);
				int bmin=b[1];
				int cnt=0;
				for(int j=1;j<=i-1;j++){
					if(b[j]==bmin)cnt++;
				}
				f[i]=cnt;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(f[i]==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
