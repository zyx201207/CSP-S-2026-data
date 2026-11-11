#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[25],dd,cnt[25][25],ans;
void dfs(int rc,int step){
	cnt[step][rc]++;
	for(int i=rc+1;i<=n&&x[i]-x[rc]<=d;i++){
		dfs(i,step+1);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	if(c==13||c==14){
//		while(t--){
//			cin>>n>>d;
//			int left,right;
//			for(int i=1;i<=n;i++){
//				cin>>a[i];
//				if(a[i]-a[1]<=d){
//					right=i;
//				}
//			}
//			for(int i=n;a[n]-a[i]<=d;i--){
//				left=i;
//			}
//			if(right-left>1){//>=3
//				cout<<0<<'\n';
//			}else if(right==left){//1
//				
//			}else{//2
//				
//			}
//		}
//	}
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				if(x[i]-x[1]<=d){
					dd=i-1;
				}
			}
			if(dd>=2){
				cout<<((n-2*dd+1)>0?(n-2*dd+1):0)<<'\n';
			}else{
				cout<<"0\n";
			}
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				for(int k=0;k<=n;k++){
					cnt[k][i]=0;
				}
			}
			dfs(j,0);
			for(int i=j;i<=n;i++){
				for(int k=0;k<=n;k++){
					if(cnt[k][i]==2){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
