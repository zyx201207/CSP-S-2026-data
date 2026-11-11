#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mn=2e6;const int maxn=mn+10;
int c,t,n,d,a[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int f=-1,b=-1;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)f=j;
				else break;
			}for(int j=f+1;j<=n;j++){
				if(a[j]-a[f]<=d)b=j;
				else break;
			}if(f==-1||b==-1)break;
			for(int j=b;j>f;j--){
				int num=0;
				for(int k=f;k>i;k--)if(a[j]-a[k]<=d)num++;
				if(num==2)ans++;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
