#include<bits/stdc++.h>
using namespace std;
long long c,T;
long long n,d;
long long a[2000005];
long long b[2000005];
long long vis[2000005];
long long ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(long long t=0;t<T;t++){
		ans=0;
		cin>>n>>d;
		cin>>a[1];
		long long flag=0;
		if(a[1]!=1){
			flag=1-a[1];
		}
		b[1]=1;
		vis[1]=1;
		for(long long i=2;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]+flag;
			vis[b[i]]=1;
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if((j-i)%d==1&&(j-i)/d==1&&vis[j]==1){
					if((j-i)%2==0){
						if(vis[j+(j-i)/2]==0){
							ans++;
						}
						else if(vis[j+(j-i)/2]==1&&j+(j-i)/2>d){
							ans++;
						}
					}
					else{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
