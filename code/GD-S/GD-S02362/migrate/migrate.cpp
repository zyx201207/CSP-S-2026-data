#include<iostream>
#include<algorithm>
using namespace std;
int c,t,n;
long long a[2000010],d,b[2000010],dis[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		b[1]=0;
		for(int i=2;i<=n;i++){
			b[i]=abs(a[i]-a[i-1]);
		}
		dis[1]=0;
		dis[2]=b[2];
		for(int i=3;i<=n;i++){
			dis[i]=dis[i-1]+b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=0;
				for(int k=i+1;k<=j-1;k++){
					if((dis[k]-dis[i])<=d&&(dis[j]-dis[k])<=d){
						x++;
					}
				}
				if(x==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
