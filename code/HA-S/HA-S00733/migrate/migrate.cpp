#include<bits/stdc++.h>
using namespace std;
long long c,t,w[2000005],n,d,dis[2000005],cnt[2000005],maxx=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int kkk=1;kkk<=t;kkk++){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>w[i];
			dis[i]=0x3fffffff;
			cnt[i]=0;
		}
		maxx=0;int ans=0;
		for(int k=1;k<=n;k++){
			dis[k]=0;cnt[k]=1;
			
			for(int i=k;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(w[j]-w[i]>d){
						break;
					}else{
						if(dis[j]>dis[i]+1){
							dis[j]=dis[i]+1;
							cnt[j]=cnt[i];
						}else if(dis[j]==dis[i]+1){
							cnt[j]+=cnt[i];
						}
					}
				}
			}
			for(int i=k;i<=n;i++){
				if(cnt[i]==2){
					ans++;
				}

			}
			for(int i=1;i<=n;i++){
				dis[i]=0x3fffffff;
				cnt[i]=0;
			}

		}
		
		cout<<ans<<'\n';
	}

	return 0;
}
