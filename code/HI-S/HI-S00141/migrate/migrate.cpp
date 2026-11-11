#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		int a[10000];
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,1+a+n);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int f=true;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[k-1]>d){
						f=false;
						break;
					}
				}
				if(f==true&&(a[j]-a[i])%2==0) ans++;
			}
		}
		cout<<(ans-3)/3;
	}


	return 0;
}

