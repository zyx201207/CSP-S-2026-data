#include<bits/stdc++.h>

using namespace std;

int c,t,n,d,x[2000000],ans=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%d",&n,&d);
		ans=0;
		for(int i=1;i<=min(3,n);i++){
			scanf("%d",&x[i]);
		}for(int i=4;i<=n;i++){
			scanf("%d",&x[i]);
			if(x[i-1]-x[i-3]<=d&&x[i]-x[i-2]<=d){
				ans++;
			}
		}cout<<ans<<"\n";
	}
	return 0;
}

