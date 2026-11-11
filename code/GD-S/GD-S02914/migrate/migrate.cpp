#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int c,T;
int n,d;
int dd[N];
int a[N];
int sum[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=a[i]-a[i-1];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int vv=i;
				int bb=j;
				int cha=0;
				cha=a[bb]-a[vv];
				if(cha<=d)continue;
				if(cha>=2*d)continue;
				ans++;
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
