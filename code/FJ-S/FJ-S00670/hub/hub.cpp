#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll x[2000006],d,b[2000006],ans;

int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		
		
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		ll ma;
		for(int i=1;i<n-2;i++){
			memset(b,0,sizeof(b));
			b[i]=1;
			for(int j=i+1;i<=n;j++){
				ll len=x[j]-x[i];
				if(len%d)ma=(len/d)+1;
				else ma=(len/d);
				for(int z=d;z>=1;z--){
					ll chu,yu;
					bool bo=0;
					if(len%z){
						bo=1;
						yu=(len%z);
						chu=(len/z)+1;	
					}else chu=(len/z);
					if(chu<ma)break;
					b[j]+=b[j-z];
					if(bo)b[j]+=b[j-yu];
				}
				if(b[j]==2)ans++;
			}
		}
		printf("%lld\n",&ans);
	}
	return 0;
}
