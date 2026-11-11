#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
typedef pair<int,int> pii;
const int N=2e6+50;
int c,T;
ll a[N],f[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n;
		ll d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			memset(f,0,sizeof(f));
			for(int j=i;j<=n;++j){
				int fl=0;
				if(a[j]-a[i]<=d)f[j]=1;
				else{
					for(int k=max((ll)i,*lower_bound(a+1,a+n+1,a[j]-d));k<j;++k){
						f[j]+=f[k];
						if(f[j]>2){
							fl=1;break;
						}
					}
					if(fl)break;
					if(f[j]==2)++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
