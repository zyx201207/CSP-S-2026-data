#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int x[N],a[N];
int c,t,n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				int k=i,tot=0,cnt=0;
				while(k<j){
					int h=k+1;
					while(h<=j){
						if(x[h]-x[k]<=d) h++;
						else if(x[h]-x[k]>d){
							h--;
							break;
						}
					}
					if(h>j) h--;
					k=h,a[++tot]=h;
				}
				for(int c=1;c<=tot;c++){
					if(x[a[c+1]]-x[a[c]-1]<=d) cnt++;
					if(x[a[c+1]]-x[a[c]-2]<=d) cnt++;
				}
				if(cnt==1) ans++;
			}
		}
		cout<<ans+1<<"\n";
	}
	return 0;
}
