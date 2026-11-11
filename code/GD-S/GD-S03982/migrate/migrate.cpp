//migrate.cpp  3/25 
#include<bits/stdc++.h>
#define MAXN 2000005 //2*1e6
using namespace std;
using ull = unsigned long long ;
using ll = long long;



int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;cin>>c>>t;
	while(t--){
		
		if(c<=6){
			//0th
			ull n,d;cin>>n>>d;
			ll x[MAXN];
			for(ull i = 1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			
			
			//1st
			ull ans = 0;
			for(ull j = 1;j<=n;j++){
				for(ull i = 1;i<j;i++){
					ull way = 0;
					for(ull k = 1;k<=n;k++){
						if(x[k]>= x[i]-d && x[k]<= x[i]+d && x[j]-x[k]<=d)way++;
					}
					if(way == 2)ans ++;
				}
			}
			
			//printf("%llu",ans);
			cout<<ans;
			cout<<endl;
		}
		
	}
} 
