#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50;
int c,t,n,d,o;
long long a[N],ans,anss;
map<long long,int> f;
void dfs(int zzd,int xd,long long jl){
	if(xd==zzd){
		f[jl]++;
		ans=min(ans,jl);
		return ;
	}
	for(int i=xd+1;i<=zzd;i++){
		if((a[i]-a[xd])<=d){
			dfs(zzd,i,jl+1);
		}
		else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
					o=1;
				}
			}
		}
		if(o==0){
			long long l=d/(a[2]-a[1])+(d%(a[2]-a[1]));
			if(l==1LL){
				cout<<0;
				continue;
			} 
			for(int i=1;i*(l+1)<=n;i++){
				ans+=(n-(i*l+1));
			}
			cout<<ans;
			continue;
		}
		o=0;
		for(int i=1;i<=n;i++){
			ans=LLONG_MAX;
			for(int j=i+3;j<=n;j++){
				dfs(j,i,0);
				if(f[ans]==2){
					anss++;
				}
				f.clear();
			}
		}
		cout<<anss<<'\n';
		anss=0;
	}
	return 0;
}
