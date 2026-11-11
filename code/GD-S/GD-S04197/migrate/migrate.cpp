#include<bits/stdc++.h>
using namespace std;
int Subtask,T;
int n,dis,d;
int a[2000001];
long long ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&Subtask,&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&dis);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		d=a[n]-a[n-1];
		if(d==a[2]-a[1]){
			if(2*d>dis){
				printf("%lld\n",ans);
				continue;
			}
			for(int i=2;i<=n/dis;i++){
				ans+=n-(i*dis)+1;
			}
			printf("%lld\n",ans);
		}
		else{
			printf("%lld\n",ans);
			continue;
		}
	}
	
	return 0;
 } 
