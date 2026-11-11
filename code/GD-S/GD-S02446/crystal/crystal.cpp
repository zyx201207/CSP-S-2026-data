#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>pli;
ll read(){
	ll k=0,f=1;
	int c=getchar();
	for(;!isdigit(c);c=getchar()){if(c=='-')f=-1;}
	for(;isdigit(c);c=getchar()){k=k*10+(c&15);}
	return f*k;
}
const int maxn=5e5+100;
ll n,m;
ll a[maxn];
ll d[maxn];
pli b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	int tot=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			b[++tot]={a[i],1};
		}else{
			b[tot].second++;
		}
	}for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	int res=1;
	int cnt=0;
	while(res+1<=n&&((cnt+(res*d[res+1]))<=m)){
		cnt+=(res*d[res+1]);
//		printf("%lld %lld %lld\n",ans,cnt,(ans)*d[ans+1]);
		res++;
	}
	ans=max(ans,res);
	printf("%lld\n",ans);
	return 0;
}
