#include<bits/stdc++.h>
using namespace std;
int c,t; long long a[2000006];
long long b[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(1<=c&&c<=10)
		while(t--){
			int n,ans=0; long long m;
			scanf("%d%lld",&n,&m);
			for(int i=1; i<=n; i++)
				scanf("%d",&a[i]);
			for(int i=1; i<n; i++){
				//i,id-1,id,j~k
				int id=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
				if(id<=i+1) continue;
				int j=upper_bound(a+1,a+1+n,a[id-2]+m)-a;
				if(j>n) continue;
				int k=upper_bound(a+1,a+1+n,a[id-1]+m)-a-1;
				k=min(k,n);
//				int sum1=1,sum2=1;
//				while(i-sum1+1>1&&a[i-sum1+2]-a[i-sum1]>m&&a[i-sum1+1]-a[i-sum1]<=m) sum1++;
//				while(k+sum2-1<n&&a[k+sum2]-a[k+sum2-2]>m&&a[k+sum2]-a[k+sum2-1]<=m) sum2++;
				ans++;
			} 
			printf("%d\n",ans);
		}
	return 0;
}

