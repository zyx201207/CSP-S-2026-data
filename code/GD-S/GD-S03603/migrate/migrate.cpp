#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int c,t;
long long n;
long long d;
long long a[2000005];
long long dm[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=300){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dm[i][j]=INF;
				}
			}
			for(int i=2;i<=n;i++){
				for(int j=1;j<i;j++){
					if(d>=a[i]-a[j]){
						dm[j][i]=1;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					if(i==k||dm[i][k]==INF) continue;
					for(int j=1;j<=n;j++){
						if(i==j||j==k||dm[k][j]==INF) continue;
						if(dm[i][k]+dm[k][j]<dm[i][j]){
							dm[i][j]=dm[i][k]+dm[k][j];
						}
					}
				}
			}
			int sum=0;
			for(int i=4;i<=n;i++){
				for(int j=1;j<i;j++){
					int cnt=0;
					for(int k=j+1;k<i;k++){
						if(j==k) continue;
						if(dm[j][k]+dm[k][i]==dm[j][i]) cnt++;
						if(cnt>2) break;
					}
					if(cnt==2) sum++;
				}
			}
			cout<<sum<<endl;
		}else{
			long long j=a[3]-a[2];
			if(j==0){
				cout<<0<<endl;
				continue;
			}
			long long s=d/j;
//			cout<<s<<endl;
			if(s<=1){
				cout<<0<<endl;
			}else{
//				cout<<n<<' ';
				cout<<max(0*1LL,n-s-s+1)<<endl;
			}
		}
	}
	return 0;
}

