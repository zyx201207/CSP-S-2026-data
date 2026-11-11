#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int C,T,n;
ll a[N],d,ans;
int f[N],g[N];
bool bz[N];
int que[N],sum[N];
void bfs(int x){
	int r=x+1;
	for(int i=x;i<=n;i++){
		while(r<=n&&a[r]-a[i]<=d)g[r++]=g[i]+1;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	//	cout<<n<<" "<<d<<" "<<a[1]<<" "<<a[2]-a[1]<<"\n";
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)f[j]=g[j]=bz[j]=0,sum[j-i]=0;
			f[i]=1,g[i]=0;
			sum[0]=1;
			bfs(i);
			int l=i;
		//	cout<<"G =";
		//	for(int j=i;j<=n;j++)cout<<g[j]<<" ";cout<<"\n";
			for(int j=i+1;j<=n;j++){
				while(a[j]-a[l]>d)sum[g[l]]-=f[l],l++;
				f[j]=sum[g[j]-1];
				if(f[j]==2)ans++;
				sum[g[j]]+=f[j];
			}
			if((C+1)/2==0){
				int x=1;
				while(x<=n&&f[x]!=2)x++;x--;
				ans=n-x;
				break;
			}
		//	cout<<"f =";
		//	for(int j=i;j<=n;j++)cout<<f[j]<<" ";cout<<"\n";
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
} /*
0 1
10 14
0 7 14 21 28 35 42 49 56 63
*/
