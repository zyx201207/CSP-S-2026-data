#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,d,a[2000005],L[2000005],R[2000005],p[2000005],q[2000005];
int sum[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p[i]=q[i]=sum[i]=0;
		}
		sum[n+1]=0;
		L[0]=1;
		for(int i=1;i<=n;i++){
			L[i]=L[i-1];
			while(a[i]-a[L[i]]>d)L[i]++;
		}
		R[n+1]=n;
		for(int i=n;i>=1;i--){
			R[i]=R[i+1];
			while(a[R[i]]-a[i]>d)R[i]--;
		}
		for(int i=1;i<=n;i++){
			p[i]++;
			if(L[i]!=i&&R[L[i]]==i){
				p[i]+=p[L[i]]-1;
			}
			if(R[i]!=i)p[R[i]]++;
		}
		for(int i=n;i>=1;i--){
			q[i]++;
			if(R[i]!=i&&L[R[i]]==i){
				q[i]+=q[R[i]]-1;
			}
			if(L[i]!=i)q[L[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(L[R[i]-1]!=i)p[i]=1;
			if(R[L[i]+1]!=i)q[i]=1;
			if(R[i]==i)p[i]=0;
			if(L[i]==i)q[i]=0;
		}
		int ans=0;
		for(int j=3;j<=n;j++){
			sum[R[j-2]]+=p[j-2];
			ans+=q[j]*sum[L[j]+1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}//rp++