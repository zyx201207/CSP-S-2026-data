#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template<typename T>
T read(){
	T k=0,f=1;
	int c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
	for(;isdigit(c);c=gc()) k=(k<<3)+(k<<1)+(c-'0');
	return k*f;
} 
template<typename T>
void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
const ll N=2e6+5;
ll a[N],cnt[N];
ll dp[N][3];
bool b[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int test_c=read<int>();
	ll n=read<ll>(),d=read<ll>();
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	a[0]=-1e9-5;
	ll p=0;
	for(int i=1;i<=n;i++){
		a[i]=read<ll>();
		
	}
	for(int i=1;i<=n;i++){
		p=i-1-cnt[i-1];
		while(a[i]-a[p]>d) p++;
		cnt[i]=i-p;
		dp[i][1]=cnt[i];
		int p=i-cnt[i];
		if((p-cnt[p]==1)&&(a[p]-a[p-cnt[p]]>=d)) dp[i][1]++;
		p=p-cnt[p];
		while(cnt[p]>0){
			dp[i][1]++;
			//write(p),putchar('\n');
			if((p-cnt[p]==1)&&(a[p]-a[p-cnt[p]]>=d)) dp[i][1]++;
			p=p-cnt[p];
		}
		//putchar('\n');
		//write(dp[i][1]),putchar('\n');
	}
	for(int i=1;i<=n;i++){
		write(i),putchar(' ');
		for(int j=1;j<=cnt[i];j++){
			dp[i][2]+=dp[i-j][2]; 
			//write(cnt[i]-j),putchar(' '),write(cnt[i]),putchar(' '),write(j),putchar('\n');
			//write(i-j-cnt[i-j]),putchar('\n');
			if((cnt[i]-j==1)&&(i-j-cnt[i-j]<i-cnt[i])){
				dp[i][2]=dp[i][2]+dp[i-j-cnt[i-j]][1]+1; 
			}
		}
		//write(dp[i][2]);
		putchar('\n');
	}
	write(dp[n][2]);
	return 0;
}
//5 2 1 2 3 4 5
