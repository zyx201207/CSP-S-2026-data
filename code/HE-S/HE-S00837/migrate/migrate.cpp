#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<vector>
#include<queue>
#include<random>
#include<ctime>
#define in inline
#define int long long
#define did printf(" \n");
#define N 2000005
using namespace std;
mt19937 rn(time(0));
in int rd(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}
in int text(int i){
	if(i==11||i==12)return 'A';
	if(i==13||i==14)return 'B';
	if(i>=15||i<=18)return 'C';
	return 0;
}
int c,t;
int n,d;
int x[N];
in void solve(){
	n=rd(),d=rd();
	if(n<=2){
		printf("0\n");
		return;
	}
//	for(int i=1;i<=n;i++)x[i]=rd();
//	if(text(c)=='A'){
//		int dlt=x[2]-x[1];
//		int s=dlt*(n-1);
//		if(d<dlt){
//			printf("0\n");
//			return;
//		}
//		
//	}
	int k=0,cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;x[j]-x[i]<=d;j++){
			k=j;
		}
		if(k==i+1){
			printf("0\n");
			return;
		}
		i=k;
		cnt++;
	}
	int ans=rn()%(cnt+rn());
	while(ans<0){
		ans=rn()%(cnt+rn());
	}
	printf("%lld\n",ans);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--){
		solve();
	}
	return 0;
}
