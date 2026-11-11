#include<bits/stdc++.h>
using namespace std;
long long ans=0,c,T,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T){
		T--;
		scanf("%lld%lld",&n,&d) ;
		if(d>=n/2){
			printf("0\n");
			return 0;
		}
		memset(a,0,sizeof a); 
		for(int i=1;i<=n;i++){
			cin>>a[i];			
		}
		int x1=a[i]-a[i-1];
		bool flag1=1;
		for(i=2;i<=n;i++){
			if(a[i]-a[i-1]!=x1)flag1=0;
		}
		if(flag1){
			if(a[1]+d>=a[3]&&a[1]<a[3])cout<< n-3<<endl;
			else cout<<0<<endl; 
			return 0;
		}
		for(int i=1;i<=n-4;i++){
			if(a[i]+d>=a[i+2]&&a[i]+d<a[i+3]&&a[i+1]+d>=a[i+3]&&a[i+1]+d<a[i+4])ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 

