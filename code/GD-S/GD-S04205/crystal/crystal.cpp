#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=0,maxi;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 0;i < n;i++){
		long long zs=0;
		for(int j = 0;j < i;j++){
			zs+=a[i]-a[j];
		}	
		if(zs > m){
			break;
		}
		maxn = max(maxn,zs);
		if(maxn==zs){
			maxi=i;
		}
	}
	maxi++;
	printf("%lld",maxi);
	return 0;
}
