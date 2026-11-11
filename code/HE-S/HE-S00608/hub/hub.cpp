#include<bits/stdc++.h>
using namespace std;

int const N=1e6+10;
long long a[N][3];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d",&c);
	scanf("%d",&t);
	while(t--){
		long long n,k;
		scanf("%lld",&n);
		scanf("%lld",&k);
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=2;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		long long minn=INT_MIN;
		long long sum=0;
		for(int i=1;i<=n-1;i++){
			if(a[i][1]<a[i][2]){
				sum+=a[i][2]-a[i][1];
			}
			else{
				sum+=a[i][1]-a[i][2];
			}
			minn=min(minn,sum);
			sum=0;
		}
		printf("%lld\n",minn);
	}
	
	return 0;
}
