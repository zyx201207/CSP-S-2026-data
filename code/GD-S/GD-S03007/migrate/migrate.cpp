#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		long long n,d;
		long long ans=0;
		memset(a,0,sizeof(a));
		scanf("%lld %lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<"\n";
//		}
		for(long long i=1;i<=n-3;i++){
			int k=a[i+1]-a[i];
//			cout<<k<<endl;
			if(k>d) continue;
			if((a[i+2]-a[i+1])==k&&(a[i+3]-a[i+2])==k){
				ans++;
//				cout<<"i="<<i<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
8129
16
9
7
12
0
0
0
2
1
0
2
3
6
0
2
0

*/
