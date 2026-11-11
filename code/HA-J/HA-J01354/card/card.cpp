#include<bits/stdc++.h>
using namespace std;
bool zt[3005];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long ans[3005]={0},x[200005];
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x[i];
	}
	for(long long i=1;i<=n;i++){
		long long js[3005];
		long long wz[3005];
		long long t=0;
		for(long long j=i;j<=n;j++){
			if(zt[x[j]]==1){
				for(long long l=wz[x[j]]+1;l<=t;l++){
					zt[js[l]]=0;
				}
				t=wz[x[j]];
			}
			else{
				t++;
				zt[x[j]]=1;
				js[t]=x[j];
				wz[x[j]]=t;
			}
		}
		for(long long p=1;p<=t;p++){
			ans[js[p]]++;
			zt[js[p]]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
