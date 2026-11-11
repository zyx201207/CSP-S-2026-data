#include<bits/stdc++.h>
using namespace std;
int T,ans,c,m,n,e,a[2000005];
int b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	while(T--){
		scanf("%d%d",&n,&m),ans=0;
		for(int i=0;i<n;i++)scanf("%d",a+i);
		for(int i=0;i<n;i++){
			int j=i;
			c=1,e=0,b=0;
			while(1){
				if(b){
					int x=upper_bound(a,a+n,a[j]+m)-a-1;
					if(x>=n||x<2)break;
					int y=upper_bound(a,a+n,a[x-1]+m)-a-1;
					int z=upper_bound(a,a+n,a[x-2]+m)-a-1;
					if(y!=z)e++;
					break;
				}else{
					int x=upper_bound(a,a+n,a[j]+m)-a-1;
					if(x>=n||x<2)break;
					int y=upper_bound(a,a+n,a[x-1]+m)-a-1;
					int z=upper_bound(a,a+n,a[x-2]+m)-a-1;
					if(y==z)break;
					else b=1;
				}
			}ans+=c*e;
		}printf("%d\n",ans);
	}
}//('.')
