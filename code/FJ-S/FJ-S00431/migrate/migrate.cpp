#include<bits/stdc++.h>
using namespace std;
long long a[2014514];
long long f[514][514];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long C,T;
	cin>>C>>T;
	while(T--){
		memset(f,0,sizeof f);
		long long n,m;
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		long long d=a[2]-a[1];
		if(C==11||C==12){
			if(m/d==1){
				cout<<0;
				continue;
			}
			cout<<n-(m/d)*2+1<<endl;
			continue;
		}
		else{
			long long ans=0;
			for(long long l=1;l<=n;l++){
				for(long long r=l;r<=n;r++){
					f[l][0]=1;
					for(long long i=1;i<=(r-l)+1;i++){
						f[l][i]=0;
					}
					for(long long i=l+1;i<=r;i++){
						for(long long j=1;j<=(r-l+1);j++){
							f[i][j]=0;
							for(long long k=i-1;k>=l;k--){
								if(a[i]-a[k]>m){
									break;
								}
								f[i][j]+=f[k][j-1];
							}
						}
					}
					long long s=0;
					for(long long i=1;i<=(r-l)+1;i++){
						if(f[r][i]){
							s=f[r][i];
							break;
						}
					}
					if(s==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}
//1145Bytes 1145B 
