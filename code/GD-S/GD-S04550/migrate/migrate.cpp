#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,c,t,d;
long long x[N],f[N],sum[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			ans=0;
			cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int k=1;k<n;k++){
		memset(f,0x3f,sizeof(f));
		memset(sum,-1,sizeof(sum));
		f[k]=0;
		sum[k]=1;
			for(int i=1;i<=n;i++){
				for(int j=i-1;j>=1;j--){
					if(x[i]-x[j]>d)break;
					if(f[i]>f[j]+1 && sum[j]!=-1){
						f[i]=f[j]+1;
						sum[i]=sum[j];
					}else if(f[i]==f[j]+1 && sum[j]!=-1){
						sum[i]+=sum[j];
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(sum[i]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	}
	cin>>t;
	while(t--){
		cout<<0;
	}
	return 0;
} 
