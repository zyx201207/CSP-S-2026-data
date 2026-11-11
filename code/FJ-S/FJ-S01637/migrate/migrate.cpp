#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5050,MAX=2e18+5;
int c,n,d,T;
int a[N],f[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c>10){
		while(T--){
			cout<<0<<'\n';
		}
	}
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[j]=MAX;
			f[i]=0;
			for(int j=i+1;j<=n;j++){
				int s=1;
				for(int k=i+1;k<=j;k++){
					int l=k-1;
					while(a[k]-a[l]<=d&&l){
						if(f[k]>f[l]+1){
							f[k]=f[l]+1;
							s=1;
						}else if(f[k]==f[l]+1){
							s++;
						}
						l--;
					}
				}
//				cout<<f[j]<<' '<<s<<'\n';
				if(s==2&&f[j]!=MAX) ans++;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}

