#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,x[N],d,ans=0,lj=0,mn;
vector<long long> a[N];
void dfs(long long id,long long zd,long long cnt){
	
	if(id==zd){
		if(mn>cnt){
			mn=cnt;
			lj=1;
		}else
		lj++;
		return;
	}
	for(int i:a[id]){
		if(i<=zd)dfs(i,zd,cnt+1);
	}
}
void solve(){
	if(n<=10){
		for(int i=1;i<=n;i++){
			a[i].clear();
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)
				a[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(j-i==1)continue;
				lj=0;
				mn=2e18;
				dfs(i,j,1);
				if(lj==2){
					ans++;
				}else if(lj==0){
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}else{
		long long ee=2,bdd=0;
		ans=0;
		x[0]=-2e18;
		if(x[2]-x[1]>d)ee=1;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]>d)ee=1;
			else if(x[i]-x[i-2]<=d){
				if(!bdd)
				bdd=1;
				else{
					ans+=ee-1;
					ee=2;
				}
			}else ee++;
		}
		
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		ans=0;
		solve();
	}
	return 0;
}
