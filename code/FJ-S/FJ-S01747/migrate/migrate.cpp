#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,c,t;
long long d,ans,a[N],f[N][2],minn[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		int v=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				v=0;
				if(a[j]-a[i]<=d)continue;
				for(int k=i;k<=j;k++){
					if(a[i]+d>=a[k] && a[j]-d<=a[k]){
						v++;
					}
				}
				if(v==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

