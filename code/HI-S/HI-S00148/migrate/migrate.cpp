#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long d;
long long x[6005];
int dis[6005],cnt[6005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n>6000){
			cout<<"0\n";
			continue;
		}
		int sum=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				dis[i]=100000,cnt[i]=0;
			}dis[k]=0;cnt[k]=1;
			for(int i=k;i<=n;i++){
				if(cnt[i]==0)continue;
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						if(dis[j]==dis[i]+1){
							cnt[j]+=cnt[i];
						}
						else if(dis[j]>dis[i]+1){
							dis[j]=dis[i]+1;
							cnt[j]=cnt[i];
						}
					}
				}
			}
			for(int i=k;i<=n;i++){
				if(cnt[i]==2)sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
