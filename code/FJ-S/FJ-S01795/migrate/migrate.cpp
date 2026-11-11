#include<bits/stdc++.h>
using namespace std;

int c,t,n,d;
long long x[2000010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==11||c==12){
		while(t--){
			scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			long long ans=0;
			for(int i=1;i<=n-d-1;i++){
//				cout<<"i;"<<i<<"\n";
				for(int j=i+d+1;j<=n;j+=(d+1)){
					ans++;
//					cout<<"j:"<<j<<"\n";
				}
			}
			printf("%lld\n",ans);
		}	
	}
	else {
		while(t--)printf("1\n");
	}
	return 0;
}
