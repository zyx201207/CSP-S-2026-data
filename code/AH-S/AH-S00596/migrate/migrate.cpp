#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int a[N],f[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f[i]=3e18;
		}
		f[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[j]+d<a[i])break;
				f[i]=min(f[i],f[j]+1);
			}
		}for(int i=2;i<=n;i++){
			int cnt=0;
			for(int j=i-1;j>=1;j--){
				if(a[j]+d<a[i])break;
				if(f[j]+1==f[i])cnt++;
			}
			if(cnt==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
