#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int f[N],da[N],s[N],js[N],k[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		int n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1; i<=n; i++)scanf("%lld",&s[i]),da[i]=0,js[i]=0,k[i]=0;
		int ans=0;
		for(int i=1,j=1; i<=n; i++){
			while(s[j+1]-s[i]<=d)j++;
			js[j]+=js[i]+1;
		}
		for(int i=1,j=1; i<=n; i++){
			while(s[i]-s[j]>d)j++;
			f[i]=j;
			if(i-j==1){
				da[i]=k[j];
				if(s[i+1]-s[j]>d)k[i]=k[j];
			}
			else if(i-j>=2){
				da[i]=f[j+2]-f[j+1];
				if(da[i]&&s[j]-s[f[j+1]-1]>d){
					da[i]+=js[f[j+1]];
				}
				da[i]+=k[j];
				if(s[i+1]-s[j+1]>d)k[i]+=da[i];
			}
			ans+=da[i];
//			cout<<da[i]<<"\n";
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000


1 1
10 3
0 1 2 3 4 5 6 7 8 9
0 0 0 0 0 1 1 1 2 2

7
6
*/
