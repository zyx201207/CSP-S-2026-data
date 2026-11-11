#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long num[2000005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>num[i];
		for(int i=1;i<n;i++){
			if(num[i+1]-num[i]>=d){
				n=i;
				break;
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if((j-i)%2!=0&&num[j]-num[i]<d*2&&num[j]-num[i]>d){
					int sum=num[j]-num[i]-d,cnt=0;
					bool Num[num[j]-num[i]-d+1];
					memset(Num,0,sizeof(Num));
					for(int k=i;k<=j;k++){
						if(num[k]-num[i]<=sum) Num[num[k]-num[i]]=1;
						if(Num[sum+d-num[j]+num[k]]!=0){
							if(cnt==0) cnt=sum+d-num[j]+num[k];
							else{
								if(cnt==num[j]-num[k]) continue;
								cnt=0;
								break;
							}
						}
					}
					if(cnt!=0) ans++;
				}else if((j-i)%2==0&&num[j]-num[i]<d*2&&num[j]-num[i]>d){
					int sum=num[j]-num[i]-d,cnt=0;
					bool Num[num[j]-num[i]-d+1];
					memset(Num,0,sizeof(Num));
					for(int k=i;k<=j;k++){
						if(num[k]-num[i]<sum) Num[num[k]-num[i]]=1;
						if(Num[sum+d-num[j]+num[k]]!=0){
							if(cnt==0) cnt=sum+d-num[j]+num[k];
							else{
								if(cnt==num[j]-num[k]) continue;
								cnt=0;
								break;
							}
						}
					}
					if(cnt!=0) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
