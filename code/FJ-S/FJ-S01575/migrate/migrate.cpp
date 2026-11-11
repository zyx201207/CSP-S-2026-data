#include<iostream>
#include<cstdio>
using namespace std;
int c,T;
int n;
long long d;
long long a[2000010];
int f[2000010];
long long sum[2000010];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<n;++i){
			f[i]=0;
			sum[i]=1;
			for(int j=i+1;j<=n;++j){
				sum[j]=0;
				f[j]=2e6;
			}
			for(int j=i+1;j<=n;++j){
				for(int k=j-1;k>=i;--k){
					if(a[j]-a[k]>d){
						break;
					}
					if(f[k]+1<f[j]){
						f[j]=f[k]+1;
						sum[j]=sum[k];
					}else if(f[k]+1==f[j]){
						sum[j]+=sum[k];
					}
				}
				if(sum[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
