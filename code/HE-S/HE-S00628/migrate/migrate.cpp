#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000010];
long long sum[2000010];
int f[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(f,0x3f,sizeof f);
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		f[0]=0;
		for(int i=1;i<=n;i++){
			
			int mi=0;
			for(int j=i;j;j--){
				if(sum[i]-sum[j-1]>d){
					mi=j+1;
					break;
				}
			}
			int fl=0;
			for(int j=i;j>=mi;j--){
				if(f[j]+1==f[i]){
					ans++;
					//cout<<"++ ";
					fl=1;
				}else if(f[j]+1<f[i]){
					if(fl==1){
						ans--;
						//cout<<"-- ";
						fl=0;
					}
					f[i]=f[j]+1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

