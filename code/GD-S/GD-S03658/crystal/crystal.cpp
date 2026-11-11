#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
template<typename T>
void read(T &x){
	char ch=getchar();bool fg=0;x=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') fg=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=(fg?-x:x);
	return ;
}
ll n,m,k,z,x,s,y,maxn;
ll a[500005],sum,ans=1;
int main(){
	//crystal
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	int t=1;sum=0;
	for(int i=1;i<=n;i++){
		x=i-t+1,sum+=a[i];
		while(t<=i&&m<a[i]*x-sum)
			sum-=a[t],t++,x=i-t+1;
		ans=max(ans,x);
	}
	printf("%lld",ans);
	return 0;
}