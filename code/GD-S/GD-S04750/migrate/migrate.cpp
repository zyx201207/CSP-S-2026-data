#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,t,n,d,a[N];
int cnt,ans[N];
int ans2;
void dfs(int k,int b,int jl){
	if(k==b+1){
		int sum=0;
		for(int i=1;i<=b;i++){
			sum+=ans[i];
		}if(sum==jl){
			cnt++;
		}return ;
	}for(int i=1;i<=d;i++){
		ans[k]=i;
		dfs(k+1,b,jl);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ans2=0;
		cin>>n>>d;
		if(d==1){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int flag=1;
				for(int k=2;k<=i;k++){
					if(a[k]-a[k-1]>d){
						flag=0;
						break;
					}
				}if(flag){
					memset(ans,0,sizeof(ans));
					cnt=0;
					int sh;
					int jl=a[j]-a[i];
					if(jl%d==0) sh=jl/d;
					else sh=jl/d+1;
					dfs(1,sh,jl);
					if(cnt==2){
//						cout<<i<<" "<<j<<endl;
						ans2++;
					}	
				}
				
			}
		}cout<<ans2<<"\n";
	}
	return 0;
}

