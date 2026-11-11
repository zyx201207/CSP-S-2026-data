#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e6+5;
int c,t;
int n;
ll d,x[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		bool work=1;ll xx=0;ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			if(i==2){
				xx=x[i]-x[i-1];
			}
			if(i>2&&x[i]-x[i-1]!=xx){
				work=0;
			}
		}
		ll k=d/xx,tot=(x[n]-x[1])/xx;
		if(k>=tot){
			printf("0\n");
		}else{
			for(int i=1;i<=tot;i++){
				if(i>=k){
					if(i%k!=0){
						ans+=(tot-i)+1;
					//	cout<<i<<" "<<k<<endl;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	
/*
0 2
5 2
1 2 3 4 5
*/	
	
	
	return 0;
} 
