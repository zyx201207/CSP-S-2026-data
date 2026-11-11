#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	long long mina=LONG_LONG_MAX,maxa=LONG_LONG_MIN;
	for(int i=1;i<=n;i++){
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
	}
	
	long long ans=0;
	for(long long i=mina;i<=maxa;i++){
		vector<long long>cost;
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				cost.push_back(i-a[j]);
			}
		}
		sort(cost.begin(),cost.end());
		long long sum=0,c=0;
		for(;sum+cost[c]<=m&&c<cost.size();c++){
			sum+=cost[c];
		}
		ans=max(ans,c);
	}
	
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
