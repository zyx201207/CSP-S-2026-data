#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e6+5;
int c,t,n,d,cnt[N];
ll x[N],f[N],sum[N],ans;

ll read(){
	int x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*t;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		
		for(int i=1;i<=n;i++){
			int j=i,k=i;
			do{
				j=lower_bound(x+1,x+n+1,x[j]-d)-x;k=upper_bound(x+1,x+n+1,x[j]-d)-x;
				int l=lower_bound(x+1,x+n+1,x[j+1]-d)-x;
				int tmp=lower_bound(x+1,x+n+1,x[j+2]-d)-x;
				if(j==k)break;
				if(l>=tmp)continue;
				f[i]+=(l-k+1);
			}while(j!=k);
			ans+=f[i];
		}
		
		printf("%lld\n",ans);
		
		for(int i=1;i<=n;i++)f[i]=0;
		ans=0;
	}
	
	return 0;
}
//purple or black
//LIFE'S NOT OUT TO GET YOU!
