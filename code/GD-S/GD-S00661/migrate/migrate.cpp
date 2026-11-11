#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int c,T,n,d,a[N],f[N],g[N],cnt=0,sum[N];
void init(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
}
void work(){
	init();
	cnt=0;
	for(int r=1;r<=n;r++){
		memset(f,0x3f,sizeof(f));
		memset(g,0,sizeof(g));
		memset(sum,0,sizeof(sum));
		f[r]=0,g[r]=1,sum[0]=1;
		for(int i=r-1,j=r;i>=1;i--){
			while(a[j]-a[i]>d&&j>i){
				sum[f[j]]-=g[j];
				j--;
			}
			if(j>i){
				f[i]=f[j]+1;
				g[i]=sum[f[j]];
				sum[f[i]]+=g[i];
			}else break;
			if(g[i]==2)cnt++;
		}
	}
	cout<<cnt<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>T;
	while(T--)work();
	return 0;
}
