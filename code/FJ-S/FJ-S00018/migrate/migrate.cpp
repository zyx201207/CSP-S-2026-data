#include <iostream>
#define N 2000005
#define int long long
using namespace std;
int c,t,n,d,a[N],minn,sum;
void dfs(int x,int ed,int cnt){
	if(cnt>minn) return;
	if(x==ed){
		if(cnt<minn){
			minn=cnt;
			sum=1;
		}else if(cnt==minn){
			++sum;
		}
		return;
	}
	for(int i=x+1;i<=ed&&a[i]-a[x]<=d;i++){
		dfs(i,ed,cnt+1);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					minn=1e9;
					sum=0;
					dfs(i,j,0);
					if(sum==2){
						++ans;
					}
				}
			}
			cout<<ans<<"\n";
		}else if(c==11||c==12){
			if(a[2]-a[1]>d){
				cout<<0<<"\n";
			}else{
				int p=d/(a[2]-a[1]);
				if(p==1){
					cout<<0<<"\n";
				}else{
					cout<<max(n-(2*p-1),0ll)<<"\n";
				}
			}
		}
	}
	return 0;
}
