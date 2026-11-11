#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,a[N],n,d,sum[N],b[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	clock_t st=clock();
	cin>>c>>t;
	while(t--){
			for(int i=1;i<=n;i++)a[i]=sum[i]=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
		//		sum[i]=a[i]+sum[i-1];
			}long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					long long u=a[i],v=a[j],v1,u1;
					u1=u+d;
					v1=v-d;
					int p=lower_bound(a+1,a+n+1,u1)-a;
					int q=lower_bound(a+1,a+n+1,u1)-a;
					if(p==n+1)p--;
					if(q-p==1)ans++;
				}

			}
			cout<<ans<<endl;
		}
//	clock_t et=clock();
//	double tt=double(et-st)/CLOCKS_PER_SEC;
//	cout<<tt<<" s";
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
 
*/
