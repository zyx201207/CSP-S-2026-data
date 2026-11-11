#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500001;
int n;
ll m;
ll a[N],sum[N];
ll f(int x,int y){return sum[y]-sum[x-1];}
ll g(int x,int y){return y*a[x]-f(x+1-y,x);}
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(sum,0,sizeof sum);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(g(i,i+1-mid)<=m) r=mid;
			else l=mid+1;
		}ans=max(ans,i+1-l);
	}cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}