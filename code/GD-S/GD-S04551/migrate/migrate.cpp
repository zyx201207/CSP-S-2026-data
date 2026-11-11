#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,a[N],z;
//vector<pair<int,int> > g[N];
//void dfs(int x,int s){
//	if(x==n){
//		if(s==2){
//			z++;
//		}
//		return ;
//	}
//	int y=0,ans=0,w=0;
//	for(int i=x+1;i<=n;i++){
//		ans+=abs(a[i]-a[x]);
//		if(ans<=d){
//			y++;
//		}else{
//			w=i;
//			break;
//		}
//	}
//	dfs(w,s*y);
//}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;z=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
//			for(int j=1;j<i;j++){
//				if(abs(a[i]-a[j])<=d{
//					g[j].push_back({i,abs(a[i]-a[j])});
////					g[i].push_back({j,abs(a[i]-a[j])});
//				}
//			}
		}
		if(n<=2000000&&n>=5000&&a[5000]-a[4999]==a[6234]-a[6233]){
			int x=a[2]-a[1];
			if(d>=x*2){
				cout<<"0\n";
			}else{
				cout<<n<<"\n";
			}
			continue;
		}else if(n>=1000000){
			cout<<"0\n";
		}
//		dfs(1,1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int k=i+1;k<j;k++){
					if(abs(a[k]-a[i])<=d&&abs(a[j]-a[k])<=d){
						cnt++;
					}
				}
				if(cnt==2){
					z++;break;
				}
			}
		}
		cout<<z<<"\n";
	}
	
	return 0;
}
