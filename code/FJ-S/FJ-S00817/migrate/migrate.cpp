#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
int f[1005][1005];
int a[500005],cnt[1005][1005],t[500005];
bool inq[500005];
int main(){
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	int C,T;
	std::cin>>C>>T;
	while(T--){
		int n,d,l=1;		
		std::cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=0x3f3f3f3f;
			}
			//f[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		for(int i=1;i<=n;i++){
			std::cin>>a[i];
			while(a[i]-a[l]>d) l++;
			for(int j=l;j<i;j++){
				//f[i][j]=1;
				f[j][i]=1;
				cnt[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==k||j==k) continue;
					int a,b,c;
					a=f[i][k];
					b=f[k][j];
					c=f[i][j];
					if(a+b<c){
						cnt[i][j]=cnt[i][k]+cnt[k][j];
						f[i][j]=a+b;
					}
					else if(a+b==c){
						cnt[i][j]+=cnt[i][k]+cnt[k][j];
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i&&cnt[i][j]==2){
					ans++;
				}
				//std::cout<<cnt[i][j]<<' ';
			} 
			//std::cout<<'\n';
		} 
		//std::cout<<ans<<'\n';
	}
	return 0;
}
