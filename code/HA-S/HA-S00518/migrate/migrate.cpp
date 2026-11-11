#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[100005],dis[100005],num[100005];
queue<int>p;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		int ans=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<=1){
			cout<<"0\n";
			continue;
		}
		int bj=0,pp=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=pp) bj=1;
		}
		if(bj==0){
			int l=a[2]-a[1];
			int k=m/l;
			if(k==1){
				cout<<"0\n";
			}
			cout<<max(n-2*k+1,(long long)0)<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) num[j]=0;
			num[i]=1;
			dis[i]=0;
			p.push(i);
			while(!p.empty()){
				int k=p.front();
				p.pop();
				for(int j=k-1;j>=1;j--){
					if(a[k]-a[j]>m) break;
					if(num[j]==0){
						p.push(j);
						num[j]=num[k];
						dis[j]=dis[k]+1;
					}else if(dis[k]+1==dis[j]){
						num[j]+=num[k];
					}
				}
			}
			p.push(i);
			while(!p.empty()){
				int k=p.front();
				p.pop();
				for(int j=k+1;j<=n;j++){
					if(a[j]-a[k]>m) break;
					if(num[j]==0){
						p.push(j);
						num[j]=num[k];
						dis[j]=dis[k]+1;
					}else if(dis[k]+1==dis[j]){
						num[j]+=num[k];
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(num[j]==2) ans++;
			}
		}
		ans/=2;
		cout<<ans<<"\n";
	}
	return 0;
} 
